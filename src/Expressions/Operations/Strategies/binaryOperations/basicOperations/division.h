#pragma once
#include "../binaryStrategy.h"
namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Division: public BinaryStrategy<Type> {
    public:
        Type evaluate(const Type& numerator,const Type& denominator) const override {
            try{
                return numerator / denominator;
            } catch (std::invalid_argument&) {
                throw std::invalid_argument("The denominator must be different from zero.");
            }
        }
};
}
}