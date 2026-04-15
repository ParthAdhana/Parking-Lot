# Parking Lot — Low Level Design (C++)

A C++ implementation of a Parking Lot system using OOP principles and the Strategy design pattern.

---

## Entities

| Entity | Description |
|---|---|
| `Vehicle` | Represents a vehicle with an ID, license number, and type (CAR / BIKE) |
| `ParkingSlot` | A single parking spot on a floor; tied to a vehicle type and has a status (AVAILABLE, OCCUPIED, etc.) |
| `ParkingFloor` | A floor in the lot containing multiple slots; maintains a type-indexed map for fast slot lookup |
| `Ticket` | Issued on entry; holds vehicle ID, slot ID, entry time, and exit time |
| `ParkingLot` | Core service that manages floors, assigns slots, and calculates fees on exit |
| `EntryGate` | Entry point — takes a vehicle and returns a ticket |
| `ExitGate` | Exit point — takes a ticket, frees the slot, and returns the fee |

## Strategies

| Strategy | Description |
|---|---|
| `SlotAllocationStrategy` | Abstract interface for slot selection |
| `NearestSlotStrategy` | Returns the first available slot (concrete implementation) |
| `PricingStrategy` | Abstract interface for fee calculation |
| `FlatRatePricingStrategy` | Charges a fixed rate per hour (concrete implementation) |

---

## UML Class Diagram

```mermaid
classDiagram
    class Vehicle {
        -int id
        -VehicleType vehicleType
        -string licenseNumber
        +getId() int
        +getVehicleType() VehicleType
        +getLicenseNumber() string
    }

    class ParkingSlot {
        +int id
        +VehicleType vehicleType
        +SlotStatus slotStatus
        +getId() int
        +getVehicleType() VehicleType
        +getSlotStatus() SlotStatus
        +setSlotStatus(SlotStatus)
        +isAvailable() bool
    }

    class ParkingFloor {
        -int floorId
        -vector~ParkingSlot*~ slots
        -map~VehicleType, vector~ParkingSlot*~~ slotsByType
        +addSlot(ParkingSlot*)
        +getSlotsByType(VehicleType) vector
        +getAllSlots() vector
    }

    class Ticket {
        +int id
        +int vehicleId
        +int slotId
        +int entryTime
        +int exitTime
        +setExitTime(int)
    }

    class ParkingLot {
        +string name
        +vector~ParkingFloor*~ floors
        +SlotAllocationStrategy* slotStrategy
        +PricingStrategy* pricingStrategy
        +addFloor(ParkingFloor*)
        +AssignSlots(Vehicle*) Ticket*
        +FreeSlots(Ticket*) double
    }

    class EntryGate {
        +int gateId
        -ParkingLot* parkingLot
        +parkVehicle(Vehicle*) Ticket*
    }

    class ExitGate {
        +int gateId
        -ParkingLot* parkingLot
        +exitVehicle(Ticket*) double
    }

    class SlotAllocationStrategy {
        <<interface>>
        +allocate(vector~ParkingSlot*~) ParkingSlot*
    }

    class NearestSlotStrategy {
        +allocate(vector~ParkingSlot*~) ParkingSlot*
    }

    class PricingStrategy {
        <<interface>>
        +calculateFee(int, int) double
    }

    class FlatRatePricingStrategy {
        -double ratePerHour
        +calculateFee(int, int) double
    }

    ParkingFloor "1" *-- "many" ParkingSlot
    ParkingLot "1" *-- "many" ParkingFloor
    ParkingLot --> SlotAllocationStrategy
    ParkingLot --> PricingStrategy
    NearestSlotStrategy ..|> SlotAllocationStrategy
    FlatRatePricingStrategy ..|> PricingStrategy
    EntryGate --> ParkingLot
    ExitGate --> ParkingLot
    ParkingLot ..> Ticket : creates
    ParkingLot ..> Vehicle : uses
```

---

## How to Run

```bash
g++ -std=c++17 main.cpp services/ParkingLot.cpp -o parking_lot && ./parking_lot
```

## Project Structure

```
Parking-Lot/
├── enums/
│   ├── VehicleType.h
│   └── SlotStatus.h
├── models/
│   ├── Vehicle.h
│   ├── ParkingSlot.h
│   ├── ParkingFloor.h
│   └── Ticket.h
├── strategies/
│   ├── PricingStratery.h
│   ├── FlatRatePricingStrategy.h
│   ├── SlotAllocationStratergy.h
│   └── NearestSlotStrategy.h
├── services/
│   ├── ParkingLot.h
│   └── ParkingLot.cpp
├── gates/
│   ├── EntryGate.h
│   └── ExitGate.h
└── main.cpp
```
