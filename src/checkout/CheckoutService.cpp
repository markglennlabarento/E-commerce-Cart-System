#include "checkout/CheckoutService.h"

#include <iostream>

std::optional<Order> CheckoutService::checkout(ShoppingCart& cart, IPaymentProcessor& pay, int orderId) {
    if (cart.empty()) {
        std::cout << "  Checkout refused: cart is empty.\n";
        return std::nullopt;
    }
    if (!pay.charge(cart.total())) {
        std::cout << "  Checkout failed: payment declined. Cart kept.\n";
        return std::nullopt;
    }
    Order order{orderId, cart.total(), cart.items().size()};
    cart.clear();
    std::cout << "  Order #" << order.id << " placed. Items: "
              << order.itemCount << "  Total: " << order.total << "\n";
    return order;
}
