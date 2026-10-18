#pragma once

#include "IShippingCalculator.h"

class FreeShippingOver : public IShippingCalculator {
public:
    FreeShippingOver(Money threshold, Money fee);

    std::string name() const override;
    Money apply(Money afterDiscount) const override;

private:
    Money threshold_;
    Money fee_;
};
