#pragma once
#include "operation.h"
#include "Strategies/operationStrategy.h"
namespace ArithmeticPoints{
namespace Expressions{
template <typename Type>
class UnaryOperation: public Operation<Type> {
    private:
        std::shared_ptr<Expression> argument;
        std::shared_ptr<Strategies::OperationStrategy<Type>> strategy;
    public:
        UnaryOperation(std::shared_ptr<Expression> argument, std::shared_ptr<Strategies::OperationStrategy<Type>> strategy):
        argument(argument), strategy(strategy) {}

        Type evaluate(Type value) const override {
            return strategy->evaluate(argument->evaluate(value));
        }

    static int getArity(){
        return 1;
    }
};
}
}