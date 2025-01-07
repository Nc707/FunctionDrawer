#pragma once
#include "../binaryStrategy.h"

template <typename Type>
class Multiplication : public BinaryStrategy<Type> {
public:
    Type evaluate(const Type& left, const Type& right) const override {
        return left * right;
    }
};