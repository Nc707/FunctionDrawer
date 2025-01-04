#pragma once
#include "variable.h"


class IntegerConstant: public Variable {
    private:
        int value;
    public:
        IntegerConstant(double value) {
            double intValue;
            if(std::modf(value, &intValue) != 0.0) {
                throw std::invalid_argument("The value must be an integer.");
            }
            this->value = static_cast<int>(intValue);
        }
        double evaluate(double x) const override {
            return value;
        }
};