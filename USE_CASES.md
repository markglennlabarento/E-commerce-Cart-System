# E-commerce Cart System — Use Cases

**System:** E-commerce Cart System (C++ console)  
**Primary actor:** Customer  
**Supporting actors:** Catalog, Payment Gateway

## Use case diagram (text)

```
                    ┌─────────────────────────┐
                    │  E-commerce Cart System │
  Customer ─────────┤                         │
    │               │  Browse catalog         │
    │               │  Add item to cart       │
    │               │  Update quantity        │
    │               │  Remove item            │
    │               │  View cart              │
    │               │  Apply coupon           │
    │               │  Remove coupon          │
    │               │  Clear cart             │
    │               │  Checkout               │
                    │                         │
                    │  ◄── Catalog            │
                    │  ◄── Payment Gateway    │
                    └─────────────────────────┘
```

---

## UC-01 Browse catalog

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | See products that can be added to the cart |
| Precondition | Catalog is loaded |
| Main flow | 1. Customer opens store. 2. System lists id, name, unit price. |
| Postcondition | Catalog is displayed; cart is unchanged |
| Extensions | — |

## UC-02 Add item to cart

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Put a product into the cart |
| Precondition | Product exists in catalog |
| Main flow | 1. Customer chooses product and quantity. 2. System validates quantity > 0. 3. System appends a new line. |
| Postcondition | Cart contains the product; subtotal increases |
| Extensions | 2a. Quantity ≤ 0 → reject with error. |

## UC-03 Merge quantity (same product)

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Add more of a product already in the cart |
| Precondition | Line for that product already exists |
| Main flow | 1. Customer adds the same product again. 2. System increases quantity on the existing line (no duplicate row). |
| Postcondition | One line per product id |

## UC-04 Update quantity

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Change how many of an item to buy |
| Precondition | Item is in the cart |
| Main flow | 1. Customer sets a new quantity > 0. 2. System updates the line total. |
| Postcondition | Quantity and totals reflect the new value |
| Extensions | 1a. Product not in cart → reject. 1b. Quantity ≤ 0 → reject. |

## UC-05 Remove item

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Delete a product line from the cart |
| Precondition | Item is in the cart |
| Main flow | 1. Customer removes product by id. 2. System drops that line. |
| Postcondition | Product is gone; totals recalculated |
| Extensions | 1a. Product not in cart → reject. |

## UC-06 View cart

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | See lines, discount, tax, shipping, and total |
| Precondition | None (empty cart is allowed) |
| Main flow | 1. Customer requests cart. 2. System shows each line and computed totals. |
| Postcondition | Display only; no data change |

## UC-07 Apply valid coupon

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Reduce the price using a known coupon |
| Precondition | Cart may be empty or filled |
| Main flow | 1. Customer enters `SAVE10`, `SAVE25`, or `USB2FOR1`. 2. Factory returns a discount strategy. 3. Totals use the new strategy. |
| Postcondition | Active discount is the matching strategy |

## UC-08 Apply invalid coupon

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Try a code that is not in the catalog |
| Precondition | None |
| Main flow | 1. Customer enters an unknown code. 2. System keeps the current discount and reports failure. |
| Postcondition | Discount strategy unchanged |

## UC-09 Remove coupon

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Go back to no discount |
| Precondition | A coupon may be active |
| Main flow | 1. Customer clears the coupon. 2. System installs `NoDiscount`. |
| Postcondition | Discount amount is $0.00 |

## UC-10 Shipping threshold

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Pay shipping only when the discounted subtotal is under $100 |
| Precondition | Free-over-$100 shipping policy is installed |
| Main flow | 1. Small cart → $7.99 shipping. 2. Adding enough items → $0.00 shipping. |
| Postcondition | Shipping fee matches the policy |

## UC-11 Checkout — success

| Field | Detail |
|---|---|
| Actor | Customer, Payment Gateway |
| Goal | Place an order |
| Precondition | Cart has at least one item |
| Main flow | 1. Customer checks out. 2. Gateway charges the total. 3. Charge succeeds. 4. System creates an order and clears the cart. |
| Postcondition | Order recorded; cart empty |

## UC-12 Checkout — empty cart

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Checkout with nothing in the cart |
| Precondition | Cart is empty |
| Main flow | 1. Customer checks out. 2. System refuses; payment is not called. |
| Postcondition | No order; cart still empty |

## UC-13 Checkout — payment declined

| Field | Detail |
|---|---|
| Actor | Customer, Payment Gateway |
| Goal | Attempt pay when the card is declined |
| Precondition | Cart has items |
| Main flow | 1. Customer checks out. 2. Gateway declines. 3. System keeps the cart; no order. |
| Postcondition | Cart unchanged |

## UC-14 Clear cart

| Field | Detail |
|---|---|
| Actor | Customer |
| Goal | Remove every line at once |
| Precondition | Cart may have items |
| Main flow | 1. Customer clears the cart. 2. All lines gone; coupon reset to none. |
| Postcondition | Empty cart, no discount |
