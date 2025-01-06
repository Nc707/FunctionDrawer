#pragma once
#include "operation.h"
#include "Strategies/operationStrategy.h"

template <typename Type>
class BinaryOperation: public Operation<Type> {
    protected:
        std::shared_ptr<Expression> izquierda;
        std::shared_ptr<Expression> derecha;
        std::shared_ptr<OperationStrategy<Type>> strategy;
    public:
        BinaryOperation(std::shared_ptr<Expression> izquierda, std::shared_ptr<Expression> derecha,
         std::shared_ptr<OperationStrategy<Type>> strategy): 
        izquierda(izquierda), derecha(derecha), strategy(strategy) {}

        Type evaluate(Type value) const override {
            return strategy->evaluate(izquierda->evaluate(value), derecha->evaluate(value));
        }
};