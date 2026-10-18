#include "Catalog.h"
#include "Product.h"
#include "ShoppingCart.h"
#include "ui/ConsoleUi.h"

int main() {
    Catalog catalog;
    catalog.add(Product(1, "Laptop Pro 14", Money(89900)));
    catalog.add(Product(2, "Wireless Mouse", Money(2499)));
    catalog.add(Product(3, "USB-C Hub", Money(1999)));

    ShoppingCart cart;
    runStore(catalog, cart);
    return 0;
}
