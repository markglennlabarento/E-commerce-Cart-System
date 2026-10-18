#include "shipping/FreeShippingOver.h"

FreeShippingOver::FreeShippingOver(Money threshold, Money fee)
    : threshold_(threshold), fee_(fee) {}

std::string FreeShippingOver::name() const { return "Free over $100"; }

Money FreeShippingOver::apply(Money afterDiscount) const {
    return threshold_ < afterDiscount ? Money(0) : fee_;
}
