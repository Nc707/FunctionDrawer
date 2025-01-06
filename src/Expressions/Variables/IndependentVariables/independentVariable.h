#pragma once
#include "../variable.h"

template <typename Type>
class IndependentVariable : public Variable<Type> {
public:
    double evaluate(Type x) const override {
        return x;
    }
};