#pragma once
#include "../binaryStrategy.h"

template <typename Type>
class Substraction : public BinaryStrategy<Type> {
public:
    double evaluate(const Type& left, const Type& right) const override {
        return left - right;
    }
};