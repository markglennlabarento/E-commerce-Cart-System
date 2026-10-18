#include "discount/DiscountFactory.h"
#include "discount/BuyXGetYFree.h"
#include "discount/NoDiscount.h"
#include "discount/PercentageDiscount.h"

std::unique_ptr<IDiscountStrategy> DiscountFactory::fromCoupon(const std::string& code) {
    if (code.empty()) return std::make_unique<NoDiscount>();
    if (code == "SAVE10") return std::make_unique<PercentageDiscount>(10);
    if (code == "SAVE25") return std::make_unique<PercentageDiscount>(25);
    if (code == "USB2FOR1") return std::make_unique<BuyXGetYFree>(1, 1, 3);
    return nullptr;
}
