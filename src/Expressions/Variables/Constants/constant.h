#pragma once
#include "../variable.h"
namespace ArithmeticPoints{
namespace Expressions{
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
}
}