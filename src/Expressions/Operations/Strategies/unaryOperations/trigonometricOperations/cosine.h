#pragma once
#include "../unaryStrategy.h"
#include <cmath>

template <typename Type>
class Cosine : public UnaryStrategy<Type> {
public:
    Type evaluate(const Type& argument) const override {
        return std::cos(argument);
    }
};