#pragma once

#include "IDiscountStrategy.h"

#include <memory>
#include <string>

class DiscountFactory {
public:
    static std::unique_ptr<IDiscountStrategy> fromCoupon(const std::string& code);
};
