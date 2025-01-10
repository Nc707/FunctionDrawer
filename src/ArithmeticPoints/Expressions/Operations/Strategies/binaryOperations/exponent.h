#pragma once
#include "binaryStrategy.h"
#include <cmath>
#include <span>
#include <stdexcept>

namespace ArithmeticPoints {
namespace Strategies {

template <typename Type>
class Exponent : public BinaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments, const StrategyConfig<Type>& config) const override {
        const Type& base = arguments[0];
        const Type& exponent = arguments[1];
        return std::pow(base, exponent);
    }
};

} // namespace Strategies
} // namespace ArithmeticPoints