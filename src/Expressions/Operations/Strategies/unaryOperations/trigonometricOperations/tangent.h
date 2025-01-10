#pragma once
#include "../unaryStrategy.h"
#include <cmath>

namespace ArithmeticPoints {
namespace Strategies {

template <typename Type>
class Tangent : public UnaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const override {
        this->checkArity(arguments.size());
        return std::tan(arguments[0]);
    }
};

} // namespace Strategies
} // namespace ArithmeticPoints