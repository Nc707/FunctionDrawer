#pragma once
#include "../variable.h"

template <typename Type>
class Constant : public Variable<Type> {
private:
    Type value;
public:
    Constant(Type value) : value(value) {}
    double evaluate(Type x) const override {
        return value;
    }
};