#pragma once
#include "../../operationStrategy.h"
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Subtraction : public BinaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const override {
        return std::accumulate(arguments.begin(), arguments.end(), Type{}, std::minus<Type>());
    }
};
}
}