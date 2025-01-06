#pragma once
#include "operation.h"
#include "Strategies/operationStrategy.h"

template <typename Type>
class UnaryOperation: public Operation<Type> {
    protected:
        std::shared_ptr<Expression> argument;
        std::shared_ptr<OperationStrategy<Type>> strategy;
    public:
        UnaryOperation(std::shared_ptr<Expression> argument, std::shared_ptr<OperationStrategy<Type>> strategy):
        argument(argument), strategy(strategy) {}

        Type evaluate(Type value) const override {
            return strategy->evaluate(argument->evaluate(value));
        }
};