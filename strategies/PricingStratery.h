#pragma once

class PricingStrategy {
public:
    virtual double calculateFee(int entryTime, int exitTime) const = 0;
    virtual ~PricingStrategy() = default;
};
