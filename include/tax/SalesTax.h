#pragma once

#include "ITaxPolicy.h"

class SalesTax : public ITaxPolicy {
public:
    explicit SalesTax(int percent);

    std::string name() const override;
    Money apply(Money taxable) const override;

private:
    int percent_;
};
