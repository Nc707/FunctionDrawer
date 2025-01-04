#pragma once
#include "variable.h"


class RealIndependentVariable: public Variable {
    public:
        double evaluate(double x) const override {
            return x;
        }
};