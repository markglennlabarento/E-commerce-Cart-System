#include "ui/ConsoleUi.h"

#include "checkout/CheckoutService.h"
#include "payment/FakeCardProcessor.h"

#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace {

int readInt(const std::string& prompt) {
    int value = 0;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Please enter a number.\n";
    }
}

std::string readLine(const std::string& prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

void printMenu() {
    std::cout << "\n=========== E-commerce Cart System ===========\n";
    std::cout << "  1. Browse catalog\n";
    std::cout << "  2. Add item to cart\n";
    std::cout << "  3. Update quantity\n";
    std::cout << "  4. Remove item\n";
    std::cout << "  5. View cart\n";
    std::cout << "  6. Apply coupon\n";
    std::cout << "  7. Remove coupon\n";
    std::cout << "  8. Clear cart\n";
    std::cout << "  9. Checkout\n";
    std::cout << "  0. Exit\n";
    std::cout << "Coupons: SAVE10, SAVE25, USB2FOR1\n";
}

}  // namespace

void printCatalog(const Catalog& catalog) {
    std::cout << std::left << std::setw(6) << "ID"
              << std::setw(22) << "Product"
              << std::right << std::setw(10) << "Price\n";
    std::cout << "----------------------------------------\n";
    for (const auto& p : catalog.products()) {
        std::cout << std::left << std::setw(6) << p.id()
                  << std::setw(22) << p.name()
                  << std::right << std::setw(10) << p.unitPrice() << "\n";
    }
}

void printCart(const ShoppingCart& cart) {
    if (cart.empty()) {
        std::cout << "  (cart is empty)\n";
        return;
    }
    std::cout << std::left << std::setw(22) << "Item"
              << std::right << std::setw(4) << "Qty"
              << std::setw(12) << "Price"
              << std::setw(12) << "Line\n";
    std::cout << "----------------------------------------\n";
    for (const auto& item : cart.items()) {
        std::cout << std::left << std::setw(22) << item.product().name()
                  << std::right << std::setw(4) << item.quantity()
                  << std::setw(12) << item.product().unitPrice()
                  << std::setw(12) << item.lineTotal() << "\n";
    }
    std::cout << "----------------------------------------\n";
    std::cout << std::left << std::setw(26) << "Subtotal"
              << std::right << std::setw(14) << cart.subtotal() << "\n";
    std::cout << std::left << std::setw(26) << ("Discount (" + cart.discount().name() + ")")
              << std::right << std::setw(14) << cart.discountAmount() << "\n";
    std::cout << std::left << std::setw(26) << ("Tax (" + cart.tax().name() + ")")
              << std::right << std::setw(14) << cart.taxAmount() << "\n";
    std::cout << std::left << std::setw(26) << ("Shipping (" + cart.shipping().name() + ")")
              << std::right << std::setw(14) << cart.shippingAmount() << "\n";
    std::cout << std::left << std::setw(26) << "TOTAL"
              << std::right << std::setw(14) << cart.total() << "\n";
}

void runStore(Catalog& catalog, ShoppingCart& cart) {
    int nextOrderId = 1001;
    while (true) {
        printMenu();
        const int choice = readInt("Choice: ");
        try {
            switch (choice) {
            case 1:
                printCatalog(catalog);
                break;
            case 2: {
                printCatalog(catalog);
                const int id = readInt("Product ID: ");
                const int qty = readInt("Quantity: ");
                const Product* product = catalog.find(id);
                if (!product) {
                    std::cout << "  Product not found.\n";
                    break;
                }
                cart.add(*product, qty);
                std::cout << "  Added " << qty << " x " << product->name() << "\n";
                break;
            }
            case 3: {
                printCart(cart);
                const int id = readInt("Product ID: ");
                const int qty = readInt("New quantity: ");
                cart.updateQuantity(id, qty);
                std::cout << "  Quantity updated.\n";
                break;
            }
            case 4: {
                printCart(cart);
                const int id = readInt("Product ID to remove: ");
                cart.remove(id);
                std::cout << "  Item removed.\n";
                break;
            }
            case 5:
                printCart(cart);
                break;
            case 6: {
                const std::string code = readLine("Coupon code: ");
                if (cart.applyCoupon(code))
                    std::cout << "  Coupon " << code << " accepted.\n";
                else
                    std::cout << "  Coupon rejected. Previous discount kept.\n";
                break;
            }
            case 7:
                cart.removeCoupon();
                std::cout << "  Coupon cleared.\n";
                break;
            case 8:
                cart.clear();
                std::cout << "  Cart cleared.\n";
                break;
            case 9: {
                printCart(cart);
                FakeCardProcessor pay(true);
                CheckoutService::checkout(cart, pay, nextOrderId++);
                break;
            }
            case 0:
                std::cout << "Goodbye.\n";
                return;
            default:
                std::cout << "  Unknown option.\n";
                break;
            }
        } catch (const std::exception& ex) {
            std::cout << "  " << ex.what() << "\n";
        }
    }
}
