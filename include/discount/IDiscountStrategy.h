#pragma once

#include "../CartItem.h"
#include "../Money.h"

#include <string>
#include <vector>

class IDiscountStrategy {
public:
    virtual ~IDiscountStrategy() = default;
    virtual std::string name() const = 0;
    virtual Money apply(Money subtotal, const std::vector<CartItem>& items) const = 0;
};
