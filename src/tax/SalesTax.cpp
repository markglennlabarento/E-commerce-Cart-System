#include "tax/SalesTax.h"

#include <string>

SalesTax::SalesTax(int percent) : percent_(percent) {}

std::string SalesTax::name() const { return std::to_string(percent_) + "% sales tax"; }

Money SalesTax::apply(Money taxable) const {
    return Money(taxable.cents() * percent_ / 100);
}
