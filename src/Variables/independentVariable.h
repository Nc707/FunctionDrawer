#pragma once
#include <memory>
#include "variable.h"
#include "all-variables.h"
#include "../Operations/operations.h"


class IndependentVariable: public Variable {
    public:
        double evaluate(double x) const override {
            return x;
        }
};