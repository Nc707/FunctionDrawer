#pragma once
#include "variable.h"


class IntegerIndependentVariable: public Variable {
    public:
        double evaluate(double x) const override {
            double intValue;
            if(modf(x, &(intValue)) != 0) {
                throw std::invalid_argument("The value must be an integer.");
            }
            return intValue;
        }
};