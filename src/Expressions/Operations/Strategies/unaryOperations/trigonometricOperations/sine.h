#pragma once
#include "../unaryStrategy.h"
#include <cmath>
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Sine : public UnaryStrategy<Type> {
public:
    Type evaluate(const Type& argument) const override {
        return std::sin(argument);
    }
};
}
}