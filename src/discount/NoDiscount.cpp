#include "discount/NoDiscount.h"

std::string NoDiscount::name() const { return "None"; }

Money NoDiscount::apply(Money, const std::vector<CartItem>&) const { return Money(0); }
