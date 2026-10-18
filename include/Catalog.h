#pragma once

#include "Product.h"

#include <vector>

class Catalog {
public:
    void add(Product product);
    const std::vector<Product>& products() const;
    const Product* find(int id) const;

private:
    std::vector<Product> products_;
};
