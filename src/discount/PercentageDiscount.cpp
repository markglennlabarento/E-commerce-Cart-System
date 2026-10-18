#include "discount/PercentageDiscount.h"

PercentageDiscount::PercentageDiscount(int percent) : percent_(percent) {}

std::string PercentageDiscount::name() const {
    return std::to_string(percent_) + "% off";
}

Money PercentageDiscount::apply(Money subtotal, const std::vector<CartItem>&) const {
    return Money(subtotal.cents() * percent_ / 100);
}
