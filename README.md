# E-commerce Cart System

A small C++17 console application that demonstrates an e-commerce shopping cart, pricing policies, coupon strategies, and checkout flow. It uses a built-in product catalog and a fake card processor; it does not connect to a real payment gateway.

## Features

- Browse the product catalog and add products to the cart.
- Merge repeated additions of the same product, update quantities, remove items, or clear the cart.
- View subtotal, discount, tax, shipping, and final total.
- Apply or remove coupons:
  - `SAVE10` — 10% off.
  - `SAVE25` — 25% off.
  - `USB2FOR1` — buy one, get one free on USB-C Hubs.
- Calculate 8% sales tax on the discounted subtotal.
- Charge $7.99 shipping when the discounted subtotal is $100 or less; shipping is free above $100.
- Check out with a simulated, approved card payment. Empty carts cannot be checked out.

The catalog is initialized in `src/main.cpp`:

| ID | Product | Unit price |
|---:|---|---:|
| 1 | Laptop Pro 14 | $899.00 |
| 2 | Wireless Mouse | $24.99 |
| 3 | USB-C Hub | $19.99 |

## Requirements

- A C++17-compatible compiler. The instructions below use `g++` in Windows PowerShell.
- No third-party libraries are required.

## Build and run

From the project root in PowerShell:

```powershell
$sources = (Get-ChildItem -Recurse -Filter *.cpp src).FullName
g++ -std=c++17 -Wall -Wextra -I include $sources -o cart_demo.exe
.\cart_demo.exe
```

In VS Code, the project also provides a **build cart** task and a **run cart (external terminal)** task.

## Using the application

Follow the numbered menu in the console:

| Option | Action |
|---:|---|
| 1 | Browse catalog |
| 2 | Add item to cart |
| 3 | Update quantity |
| 4 | Remove item |
| 5 | View cart and totals |
| 6 | Apply coupon |
| 7 | Remove coupon |
| 8 | Clear cart |
| 9 | Check out |
| 0 | Exit |

Quantities must be greater than zero. Adding a product already in the cart increases its existing quantity rather than creating another line. An unknown coupon is rejected without replacing the current discount.

## Project layout

```text
include/    Public interfaces and class declarations
src/        Implementations and the console application entry point
USE_CASES.md
            Detailed use-case descriptions
```

## Use cases

See [USE_CASES.md](USE_CASES.md) for the system's detailed functional use cases.
