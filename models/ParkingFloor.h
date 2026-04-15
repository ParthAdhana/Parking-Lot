#pragma once

#include <vector>
#include <unordered_map>
#include "../models/ParkingSlot.h"
#include "../enums/VehicleType.h"

class ParkingFloor {
private:
    int floorId;

    // All slots
    std::vector<ParkingSlot*> slots;

    // Optimized lookup: vehicleType → slots
    std::unordered_map<VehicleType, std::vector<ParkingSlot*>> slotsByType;

public:
    ParkingFloor(int id) : floorId(id) {}

    int getFloorId() const {
        return floorId;
    }

    // Add slot to floor
    void addSlot(ParkingSlot* slot) {
        slots.push_back(slot);
        slotsByType[slot->getVehicleType()].push_back(slot);
    }

    // Get slots of a particular type
    std::vector<ParkingSlot*>& getSlotsByType(VehicleType type) {
        return slotsByType[type];
    }

    // Get all slots
    std::vector<ParkingSlot*>& getAllSlots() {
        return slots;
    }
};