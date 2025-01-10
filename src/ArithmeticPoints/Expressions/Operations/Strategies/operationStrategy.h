#pragma once
#include "../strategyConfig.h"
#include <span>

namespace ArithmeticPoints{
namespace Strategies{
template<typename Type>
class OperationStrategy {
public:
    virtual Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const = 0;
};
}
}