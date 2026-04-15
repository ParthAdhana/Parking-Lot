#include <iostream>
#include "models/Vehicle.h"
#include "models/ParkingFloor.h"
#include "models/ParkingSlot.h"
#include "models/Ticket.h"
#include "services/ParkingLot.h"
#include "strategies/FlatRatePricingStrategy.h"
#include "strategies/NearestSlotStrategy.h"
#include "gates/EntryGate.h"
#include "gates/ExitGate.h"

int main() {
    // Create strategies
    NearestSlotStrategy* slotStrategy = new NearestSlotStrategy();
    FlatRatePricingStrategy* pricingStrategy = new FlatRatePricingStrategy(50.0); // Rs.50 per hour

    // Create parking lot
    ParkingLot* lot = new ParkingLot("City Mall Parking", slotStrategy, pricingStrategy);

    // Floor 1: 2 car slots, 1 bike slot
    ParkingFloor* floor1 = new ParkingFloor(1);
    floor1->addSlot(new ParkingSlot(101, VehicleType::CAR));
    floor1->addSlot(new ParkingSlot(102, VehicleType::CAR));
    floor1->addSlot(new ParkingSlot(103, VehicleType::BIKE));
    lot->addFloor(floor1);

    // Floor 2: 1 car slot, 1 bike slot
    ParkingFloor* floor2 = new ParkingFloor(2);
    floor2->addSlot(new ParkingSlot(201, VehicleType::CAR));
    floor2->addSlot(new ParkingSlot(202, VehicleType::BIKE));
    lot->addFloor(floor2);

    // Create gates
    EntryGate* entry = new EntryGate(1, lot);
    ExitGate* exitGate = new ExitGate(1, lot);

    // Park a car
    Vehicle* car = new Vehicle(1, VehicleType::CAR, "DL01AB1234");
    Ticket* carTicket = entry->parkVehicle(car);
    if (carTicket) {
        std::cout << "Car parked. Ticket ID: " << carTicket->id
                  << ", Slot: " << carTicket->slotId << std::endl;
    } else {
        std::cout << "No slot available for car." << std::endl;
    }

    // Park a bike
    Vehicle* bike = new Vehicle(2, VehicleType::BIKE, "DL02CD5678");
    Ticket* bikeTicket = entry->parkVehicle(bike);
    if (bikeTicket) {
        std::cout << "Bike parked. Ticket ID: " << bikeTicket->id
                  << ", Slot: " << bikeTicket->slotId << std::endl;
    } else {
        std::cout << "No slot available for bike." << std::endl;
    }

    // Exit car
    double fee = exitGate->exitVehicle(carTicket);
    std::cout << "Car exited. Fee: Rs." << fee << std::endl;

    return 0;
}
