#pragma once
#include "../operationStrategy.h"

template<typename Type>
class BinaryStrategy: public OperationStrategy<Type> {
public:
    Type evaluate(const Type& argument) const override{
        throw std::invalid_argument("Binary operation requires two arguments.");
    }
};