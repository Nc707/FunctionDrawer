#pragma once
#include "binaryStrategy.h"
#include <cmath>
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Exponent : public BinaryStrategy<Type> {
public:
    Type evaluate(const Type& base, const Type& exponent) const override {
        return std::pow(base, exponent);
    }
};
}
}