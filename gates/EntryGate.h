#pragma once
#include "../services/ParkingLot.h"
#include "../models/Vehicle.h"
#include "../models/Ticket.h"

class EntryGate {
public:
    int gateId;

private:
    ParkingLot* parkingLot;

public:
    EntryGate(int id, ParkingLot* lot) : gateId(id), parkingLot(lot) {}

    Ticket* parkVehicle(Vehicle* vehicle) {
        return parkingLot->AssignSlots(vehicle);
    }
};
