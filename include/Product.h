#pragma once

#include "Money.h"

#include <string>

class Product {
public:
    Product(int id, std::string name, Money unitPrice);

    int id() const;
    const std::string& name() const;
    Money unitPrice() const;

private:
    int id_;
    std::string name_;
    Money unitPrice_;
};
