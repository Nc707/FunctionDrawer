#pragma once
#include "../unaryStrategy.h"
#include <cmath>

namespace ArithmeticPoints {
namespace Strategies {

template <typename Type>
class Cosine : public UnaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments,const StrategyConfig<Type>& config) const override {
        this->checkArity(arguments.size());
        return std::cos(arguments[0]);
    }
};

} // namespace Strategies
} // namespace ArithmeticPoints