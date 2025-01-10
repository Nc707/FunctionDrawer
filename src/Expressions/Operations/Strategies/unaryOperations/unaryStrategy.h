#pragma once
#include "../operationStrategy.h"

namespace ArithmeticPoints{
namespace Strategies{
template<typename Type>
class UnaryStrategy: public OperationStrategy<Type> {
protected:
    void checkArity(size_t arity) const{
        if(arity != 1){
            throw std::invalid_argument("Unary operation requires only one argument.");
        }
    }
};
}
}