#pragma once
#include "all-variables.h"
#include "../Operations/operations.h"

class Constant: public Variable {
    private:
        double value;
    public:
        Constant(double value): value(value) {}
        double evaluate(double x) const override {
            return value;
        }
};