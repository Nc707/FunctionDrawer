#pragma once
#include "unaryStrategy.h"

namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Negation: public UnaryStrategy<Type> {
public:
    Type evaluate(std::span<const Type> arguments, const StrategyConfig<Type>& config) const override {
        this->checkArity(arguments.size());
        return -arguments[0];
    }
};
}
}