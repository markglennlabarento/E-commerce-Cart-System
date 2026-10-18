#pragma once

#include "IDiscountStrategy.h"

class PercentageDiscount : public IDiscountStrategy {
public:
    explicit PercentageDiscount(int percent);

    std::string name() const override;
    Money apply(Money subtotal, const std::vector<CartItem>& items) const override;

private:
    int percent_;
};
