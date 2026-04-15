#pragma once
#include "../enums/SlotStatus.h"
#include "../enums/VehicleType.h"

class ParkingSlot {
public:
    int id;
    VehicleType vehicleType;
    SlotStatus slotStatus;

    ParkingSlot(int id, VehicleType type)
        : id(id), vehicleType(type), slotStatus(SlotStatus::AVAILABLE) {}

    int getId() const { return id; }
    VehicleType getVehicleType() const { return vehicleType; }
    SlotStatus getSlotStatus() const { return slotStatus; }
    void setSlotStatus(SlotStatus status) { slotStatus = status; }
    bool isAvailable() const { return slotStatus == SlotStatus::AVAILABLE; }
};
