#pragma once

#include "IDiscountStrategy.h"

class NoDiscount : public IDiscountStrategy {
public:
    std::string name() const override;
    Money apply(Money subtotal, const std::vector<CartItem>& items) const override;
};
