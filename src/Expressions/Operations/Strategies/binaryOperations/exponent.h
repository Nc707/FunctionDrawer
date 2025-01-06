#pragma once
#include "binaryStrategy.h"
#include <cmath>

template <typename Type>
class Exponent : public BinaryStrategy<Type> {
public:
    double evaluate(const Type& base, const Type& exponent) const override {
        return std::pow(base, exponent);
    }
};