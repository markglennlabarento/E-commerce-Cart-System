#pragma once

#include "../ShoppingCart.h"
#include "../payment/IPaymentProcessor.h"
#include "Order.h"

#include <optional>

class CheckoutService {
public:
    static std::optional<Order> checkout(ShoppingCart& cart, IPaymentProcessor& pay, int orderId);
};
