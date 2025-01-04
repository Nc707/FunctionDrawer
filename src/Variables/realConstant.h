#pragma once
#include "variable.h"

class RealConstant: public Variable {
    private:
        double value;
    public:
        RealConstant(double value): value(value) {}
        double evaluate(double x) const override {
            return value;
        }
};