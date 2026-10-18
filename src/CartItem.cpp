#include "CartItem.h"

#include <stdexcept>
#include <utility>

CartItem::CartItem(Product product, int quantity)
    : product_(std::move(product)), quantity_(quantity) {
    if (quantity_ <= 0) throw std::invalid_argument("quantity must be > 0");
}

const Product& CartItem::product() const { return product_; }
int CartItem::quantity() const { return quantity_; }
Money CartItem::lineTotal() const { return product_.unitPrice() * quantity_; }

void CartItem::setQuantity(int q) {
    if (q <= 0) throw std::invalid_argument("quantity must be > 0");
    quantity_ = q;
}

void CartItem::add(int extra) { setQuantity(quantity_ + extra); }
