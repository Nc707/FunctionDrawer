#pragma once
#include "../../operationStrategy.h"
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Division: public BinaryStrategy<Type> {
    public:
        Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const override {
           return std::reduce(arguments.begin() + 1, arguments.end(), arguments[0], std::divides<Type>());
        }
};
}
}