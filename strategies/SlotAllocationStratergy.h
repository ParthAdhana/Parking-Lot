#pragma once
#include <vector>
#include "../models/ParkingSlot.h"

class SlotAllocationStrategy {
public:
    virtual ParkingSlot* allocate(std::vector<ParkingSlot*>& slots) = 0;
    virtual ~SlotAllocationStrategy() = default;
};
