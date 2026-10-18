#include "payment/FakeCardProcessor.h"

#include <iostream>

FakeCardProcessor::FakeCardProcessor(bool approve) : approve_(approve) {}

std::string FakeCardProcessor::name() const {
    return approve_ ? "Visa ****4242" : "Visa ****0002";
}

bool FakeCardProcessor::charge(Money amount) {
    if (!approve_) {
        std::cout << "  Charging " << amount << " via " << name() << "... DECLINED\n";
        return false;
    }
    std::cout << "  Charging " << amount << " via " << name() << "... OK\n";
    return true;
}
