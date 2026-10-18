#pragma once

#include <iosfwd>

class Money {
public:
    explicit Money(long long cents = 0);

    long long cents() const;

    Money operator+(Money other) const;
    Money operator-(Money other) const;
    Money operator*(int qty) const;
    bool operator<(Money other) const;

    friend std::ostream& operator<<(std::ostream& os, Money m);

private:
    long long cents_;
};
