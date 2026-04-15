#pragma once
#include "SlotAllocationStratergy.h"

class NearestSlotStrategy : public SlotAllocationStrategy {
public:
    ParkingSlot* allocate(std::vector<ParkingSlot*>& slots) override {
        for (ParkingSlot* slot : slots) {
            if (slot->isAvailable()) {
                return slot;
            }
        }
        return nullptr;
    }
};
