#include "./ParkingLot.h"
#include <ctime>
#include <stdexcept>

ParkingLot::ParkingLot(const std::string& name, SlotAllocationStrategy* slotStrat, PricingStrategy* priceStrat)
    : name(name), slotStrategy(slotStrat), pricingStrategy(priceStrat), nextTicketId(1) {}

void ParkingLot::addFloor(ParkingFloor* floor) {
    floors.push_back(floor);
    for (ParkingSlot* slot : floor->getAllSlots()) {
        slotMap[slot->getId()] = slot;
    }
}

Ticket* ParkingLot::AssignSlots(Vehicle* vehicle) {
    for (ParkingFloor* floor : floors) {
        std::vector<ParkingSlot*>& slots = floor->getSlotsByType(vehicle->getVehicleType());
        ParkingSlot* slot = slotStrategy->allocate(slots);
        if (slot != nullptr) {
            slot->setSlotStatus(SlotStatus::OCCUPIED);
            int entryTime = static_cast<int>(std::time(nullptr));
            return new Ticket(nextTicketId++, vehicle->getId(), slot->getId(), entryTime);
        }
    }
    return nullptr;
}

double ParkingLot::FreeSlots(Ticket* ticket) {
    auto it = slotMap.find(ticket->slotId);
    if (it == slotMap.end()) {
        throw std::runtime_error("Slot not found");
    }
    int exitTime = static_cast<int>(std::time(nullptr));
    ticket->setExitTime(exitTime);
    it->second->setSlotStatus(SlotStatus::AVAILABLE);
    return pricingStrategy->calculateFee(ticket->entryTime, ticket->exitTime);
}
