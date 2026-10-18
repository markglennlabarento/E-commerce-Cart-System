#include "Product.h"

#include <utility>

Product::Product(int id, std::string name, Money unitPrice)
    : id_(id), name_(std::move(name)), unitPrice_(unitPrice) {}

int Product::id() const { return id_; }
const std::string& Product::name() const { return name_; }
Money Product::unitPrice() const { return unitPrice_; }
