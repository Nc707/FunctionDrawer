#pragma once
#include "../operationStrategy.h"
namespace ArithmeticPoints{
namespace Strategies{
template<typename Type>
class BinaryStrategy: public OperationStrategy<Type> {
public:
    Type evaluate(const Type& argument) const override{
        throw std::invalid_argument("Binary operation requires two arguments.");
    }
    int getArity() const override{
        return 2;
    }
};
}
}