#pragma once

#include "../Money.h"

#include <string>

class ITaxPolicy {
public:
    virtual ~ITaxPolicy() = default;
    virtual std::string name() const = 0;
    virtual Money apply(Money taxable) const = 0;
};
