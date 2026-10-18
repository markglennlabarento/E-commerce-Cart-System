#pragma once

#include "../Money.h"

#include <string>

class IShippingCalculator {
public:
    virtual ~IShippingCalculator() = default;
    virtual std::string name() const = 0;
    virtual Money apply(Money afterDiscount) const = 0;
};
