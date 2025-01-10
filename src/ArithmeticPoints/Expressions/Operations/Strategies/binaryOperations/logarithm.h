#pragma once
#include "binaryStrategy.h"
#include <cmath>
#include <span>
#include <stdexcept>

namespace ArithmeticPoints {
namespace Strategies {

template <typename Type>
class Logarithm : public BinaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments, const StrategyConfig<Type>& config) const override {
        const Type& base = arguments[0];
        const Type& argument = arguments[1];
        if (base <= 0 || argument <= 0) {
            throw std::invalid_argument("The base and the argument must be positive.");
        }
        return std::log(argument) / std::log(base);
    }
};

} // namespace Strategies
} // namespace ArithmeticPoints