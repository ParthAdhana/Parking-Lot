#pragma once
#include <string>
#include "../enums/VehicleType.h"

class Vehicle {
private:
    int id;
    VehicleType vehicleType;
    std::string licenseNumber;

public:
    Vehicle(int id, VehicleType type, const std::string& license)
        : id(id), vehicleType(type), licenseNumber(license) {}

    int getId() const { return id; }
    VehicleType getVehicleType() const { return vehicleType; }
    const std::string& getLicenseNumber() const { return licenseNumber; }
};