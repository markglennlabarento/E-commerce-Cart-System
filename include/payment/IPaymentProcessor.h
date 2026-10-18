#pragma once

#include "../Money.h"

#include <string>

class IPaymentProcessor {
public:
    virtual ~IPaymentProcessor() = default;
    virtual std::string name() const = 0;
    virtual bool charge(Money amount) = 0;
};
