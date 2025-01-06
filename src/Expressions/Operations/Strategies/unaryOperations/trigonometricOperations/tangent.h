#pragma once
#include "../unaryStrategy.h"
#include <cmath>

template <typename Type>
class Tangent : public UnaryStrategy<Type> {
public:
    double evaluate(const Type& argument) const override {
        return std::tan(argument);
    }
};