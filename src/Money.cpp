#include "Money.h"

#include <iomanip>
#include <ostream>

Money::Money(long long cents) : cents_(cents) {}

long long Money::cents() const { return cents_; }

Money Money::operator+(Money other) const { return Money(cents_ + other.cents_); }
Money Money::operator-(Money other) const { return Money(cents_ - other.cents_); }
Money Money::operator*(int qty) const { return Money(cents_ * qty); }
bool Money::operator<(Money other) const { return cents_ < other.cents_; }

std::ostream& operator<<(std::ostream& os, Money m) {
    os << '$' << (m.cents_ / 100) << '.'
       << std::setw(2) << std::setfill('0') << (m.cents_ % 100)
       << std::setfill(' ');
    return os;
}
