#pragma once
#include "../binaryStrategy.h"

template <typename Type>
class Addition: public BinaryStrategy<Type> {
    public:
        Type evaluate(const Type& left,const Type& right) const override {
            return left + right;
        }
};