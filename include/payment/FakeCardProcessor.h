#pragma once

#include "IPaymentProcessor.h"

class FakeCardProcessor : public IPaymentProcessor {
public:
    explicit FakeCardProcessor(bool approve = true);

    std::string name() const override;
    bool charge(Money amount) override;

private:
    bool approve_;
};
