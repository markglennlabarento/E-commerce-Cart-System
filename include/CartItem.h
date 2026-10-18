#pragma once

#include "Product.h"

class CartItem {
public:
    CartItem(Product product, int quantity);

    const Product& product() const;
    int quantity() const;
    Money lineTotal() const;

    void setQuantity(int q);
    void add(int extra);

private:
    Product product_;
    int quantity_;
};
