#pragma once

#include "IDiscountStrategy.h"

class BuyXGetYFree : public IDiscountStrategy {
public:
    BuyXGetYFree(int buy, int free, int productId);

    std::string name() const override;
    Money apply(Money subtotal, const std::vector<CartItem>& items) const override;

private:
    int buy_;
    int free_;
    int productId_;
};
