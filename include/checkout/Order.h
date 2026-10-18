#pragma once

#include "../Money.h"

#include <cstddef>

struct Order {
    int id;
    Money total;
    std::size_t itemCount;
};
