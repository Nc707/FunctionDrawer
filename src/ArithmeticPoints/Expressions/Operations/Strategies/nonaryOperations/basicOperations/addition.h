#pragma once
#include "../../operationStrategy.h"
#include <numeric>
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Addition: public OperationStrategy<Type> {
    public:
        Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const override {
            return std::accumulate(arguments.begin(), arguments.end(), (Type)0);
        }
};
}
}