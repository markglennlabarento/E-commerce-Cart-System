#include "ShoppingCart.h"
#include "discount/DiscountFactory.h"
#include "discount/NoDiscount.h"
#include "shipping/FreeShippingOver.h"
#include "tax/SalesTax.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

ShoppingCart::ShoppingCart()
    : discount_(std::make_unique<NoDiscount>()),
      tax_(std::make_unique<SalesTax>(8)),
      shipping_(std::make_unique<FreeShippingOver>(Money(10000), Money(799))) {}

void ShoppingCart::add(const Product& product, int qty) {
    if (qty <= 0) throw std::invalid_argument("quantity must be > 0");
    for (auto& item : items_) {
        if (item.product().id() == product.id()) {
            item.add(qty);
            return;
        }
    }
    items_.emplace_back(product, qty);
}

void ShoppingCart::updateQuantity(int productId, int qty) {
    for (auto& item : items_) {
        if (item.product().id() == productId) {
            item.setQuantity(qty);
            return;
        }
    }
    throw std::invalid_argument("product not in cart");
}

void ShoppingCart::remove(int productId) {
    auto it = std::remove_if(items_.begin(), items_.end(),
        [productId](const CartItem& item) {
            return item.product().id() == productId;
        });
    if (it == items_.end()) throw std::invalid_argument("product not in cart");
    items_.erase(it, items_.end());
}

void ShoppingCart::clear() {
    items_.clear();
    discount_ = std::make_unique<NoDiscount>();
}

bool ShoppingCart::applyCoupon(const std::string& code) {
    auto strategy = DiscountFactory::fromCoupon(code);
    if (!strategy) return false;
    discount_ = std::move(strategy);
    return true;
}

void ShoppingCart::removeCoupon() { discount_ = std::make_unique<NoDiscount>(); }

bool ShoppingCart::empty() const { return items_.empty(); }
const std::vector<CartItem>& ShoppingCart::items() const { return items_; }
const IDiscountStrategy& ShoppingCart::discount() const { return *discount_; }
const ITaxPolicy& ShoppingCart::tax() const { return *tax_; }
const IShippingCalculator& ShoppingCart::shipping() const { return *shipping_; }

Money ShoppingCart::subtotal() const {
    Money sum;
    for (const auto& item : items_) sum = sum + item.lineTotal();
    return sum;
}

Money ShoppingCart::discountAmount() const { return discount_->apply(subtotal(), items_); }
Money ShoppingCart::afterDiscount() const { return subtotal() - discountAmount(); }
Money ShoppingCart::taxAmount() const { return tax_->apply(afterDiscount()); }
Money ShoppingCart::shippingAmount() const { return shipping_->apply(afterDiscount()); }
Money ShoppingCart::total() const { return afterDiscount() + taxAmount() + shippingAmount(); }
