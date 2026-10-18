#include "discount/BuyXGetYFree.h"

#include <algorithm>
#include <string>

BuyXGetYFree::BuyXGetYFree(int buy, int free, int productId)
    : buy_(buy), free_(free), productId_(productId) {}

std::string BuyXGetYFree::name() const {
    return "Buy " + std::to_string(buy_) + " get " + std::to_string(free_) + " free";
}

Money BuyXGetYFree::apply(Money, const std::vector<CartItem>& items) const {
    for (const auto& item : items) {
        if (item.product().id() != productId_) continue;
        int groups = item.quantity() / (buy_ + free_);
        int leftover = item.quantity() % (buy_ + free_);
        int freeUnits = groups * free_ + std::max(0, leftover - buy_);
        return item.product().unitPrice() * freeUnits;
    }
    return Money(0);
}
