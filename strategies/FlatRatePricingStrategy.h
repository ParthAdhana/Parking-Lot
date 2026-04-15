#pragma once
#include "PricingStratery.h"

class FlatRatePricingStrategy : public PricingStrategy {
private:
    double ratePerHour;

public:
    FlatRatePricingStrategy(double rate) : ratePerHour(rate) {}

    double calculateFee(int entryTime, int exitTime) const override {
        double durationHours = (exitTime - entryTime) / 3600.0;
        return durationHours * ratePerHour;
    }
};
