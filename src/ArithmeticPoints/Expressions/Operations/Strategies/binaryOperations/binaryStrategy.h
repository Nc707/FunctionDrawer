#pragma once
#include "../operationStrategy.h"
namespace ArithmeticPoints{
namespace Strategies{
template<typename Type>
class BinaryStrategy: public OperationStrategy<Type> {
protected:
    void checkArity(int arity) const{
        if(arity != 2){
            throw std::invalid_argument("Binary operation requires two arguments.");
        }
    }
};
}
}