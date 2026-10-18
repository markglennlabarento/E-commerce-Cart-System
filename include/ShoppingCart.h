#pragma once

#include "CartItem.h"
#include "discount/IDiscountStrategy.h"
#include "shipping/IShippingCalculator.h"
#include "tax/ITaxPolicy.h"

#include <memory>
#include <string>
#include <vector>

class ShoppingCart {
public:
    ShoppingCart();

    void add(const Product& product, int qty);
    void updateQuantity(int productId, int qty);
    void remove(int productId);
    void clear();

    bool applyCoupon(const std::string& code);
    void removeCoupon();

    bool empty() const;
    const std::vector<CartItem>& items() const;
    const IDiscountStrategy& discount() const;
    const ITaxPolicy& tax() const;
    const IShippingCalculator& shipping() const;

    Money subtotal() const;
    Money discountAmount() const;
    Money afterDiscount() const;
    Money taxAmount() const;
    Money shippingAmount() const;
    Money total() const;

private:
    std::vector<CartItem> items_;
    std::unique_ptr<IDiscountStrategy> discount_;
    std::unique_ptr<ITaxPolicy> tax_;
    std::unique_ptr<IShippingCalculator> shipping_;
};
