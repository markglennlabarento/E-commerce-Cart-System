#include "Catalog.h"

#include <utility>

void Catalog::add(Product product) { products_.push_back(std::move(product)); }

const std::vector<Product>& Catalog::products() const { return products_; }

const Product* Catalog::find(int id) const {
    for (const auto& p : products_) {
        if (p.id() == id) return &p;
    }
    return nullptr;
}
