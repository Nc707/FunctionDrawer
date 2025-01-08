#pragma once
#include "../operationStrategy.h"

namespace ArithmeticPoints{
namespace Strategies{
template<typename Type>
class UnaryStrategy: public OperationStrategy<Type> {
public:
    Type evaluate(const Type& left, const Type& right) const override{
        throw std::invalid_argument("Unary operation requires only one argument.");
    }
    int getArity() const override{
        return 1;
    }
};
}
}