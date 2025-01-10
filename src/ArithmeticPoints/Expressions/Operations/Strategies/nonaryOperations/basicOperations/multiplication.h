#pragma once
#include "../../operationStrategy.h"
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Multiplication : public BinaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const override {
        return std::accumulate(arguments.begin(), arguments.end(), static_cast<Type>(1), std::multiplies<Type>());
    }
};
}
}