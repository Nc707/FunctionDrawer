#pragma once
#include "binaryStrategy.h"
#include <cmath>

template <typename Type>
class Logarithm : public BinaryStrategy<Type> {
public:
    double evaluate(const Type& base, const Type& argument) const override {
        if (base <= 0 || argument <= 0) {
            throw std::invalid_argument("The base and the argument must be positive.");
        }
        return std::log(argument) / std::log(base);
    }
};