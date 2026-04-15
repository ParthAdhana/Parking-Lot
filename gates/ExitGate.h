#pragma once
#include "../services/ParkingLot.h"
#include "../models/Ticket.h"

class ExitGate {
public:
    int gateId;

private:
    ParkingLot* parkingLot;

public:
    ExitGate(int id, ParkingLot* lot) : gateId(id), parkingLot(lot) {}

    double exitVehicle(Ticket* ticket) {
        return parkingLot->FreeSlots(ticket);
    }
};