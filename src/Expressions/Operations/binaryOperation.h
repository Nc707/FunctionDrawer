#pragma once
#include "operation.h"
#include "Strategies/operationStrategy.h"

namespace ArithmeticPoints{
namespace Expressions{
template <typename Type>
class BinaryOperation: public Operation<Type> {
    private:
        static const int ARITY = 2;
        std::shared_ptr<Expression> izquierda;
        std::shared_ptr<Expression> derecha;
        std::shared_ptr<Strategies::OperationStrategy<Type>> strategy;
    public:
        BinaryOperation(std::shared_ptr<Expression> izquierda, std::shared_ptr<Expression> derecha,
         std::shared_ptr<Strategies::OperationStrategy<Type>> strategy): 
        izquierda(izquierda), derecha(derecha), strategy(strategy) {}

        Type evaluate(Type value) const override {
            return strategy->evaluate(izquierda->evaluate(value), derecha->evaluate(value));
        }

        static int getArity(){
            return ARITY;
        }
};
}
}