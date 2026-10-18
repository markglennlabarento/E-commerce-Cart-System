#pragma once

#include "../Catalog.h"
#include "../ShoppingCart.h"

void printCatalog(const Catalog& catalog);
void printCart(const ShoppingCart& cart);
void runStore(Catalog& catalog, ShoppingCart& cart);
