#pragma once
#include "../unaryStrategy.h"
#include <cmath>

template <typename Type>
class Sine : public UnaryStrategy<Type> {
public:
    double evaluate(const Type& argument) const override {
        return std::sin(argument);
    }
};