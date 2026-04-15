#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "../models/ParkingFloor.h"
#include "../models/Ticket.h"
#include "../models/Vehicle.h"
#include "../strategies/SlotAllocationStratergy.h"
#include "../strategies/PricingStratery.h"

class ParkingLot {
public:
    std::string name;
    std::vector<ParkingFloor*> floors;
    SlotAllocationStrategy* slotStrategy;
    PricingStrategy* pricingStrategy;

private:
    int nextTicketId;
    std::unordered_map<int, ParkingSlot*> slotMap;

public:
    ParkingLot(const std::string& name, SlotAllocationStrategy* slotStrat, PricingStrategy* priceStrat);

    void addFloor(ParkingFloor* floor);
    Ticket* AssignSlots(Vehicle* vehicle);
    double FreeSlots(Ticket* ticket);
};