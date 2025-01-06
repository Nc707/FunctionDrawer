#pragma once
#include "../binaryStrategy.h"

template <typename Type>
class Division: public BinaryStrategy<Type> {
    public:
        double evaluate(const Type& numerator,const Type& denominator) const override {
            try{
                return numerator / denominator;
            } catch (std::invalid_argument&) {
                throw std::invalid_argument("The denominator must be different from zero.");
            }
        }
};