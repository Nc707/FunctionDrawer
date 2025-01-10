#pragma once
#include "../variable.h"

namespace ArithmeticPoints{
namespace Expressions{
template <typename Type>
class IndependentVariable : public Variable<Type> {
public:
    double evaluate(Type x) const override {
        return x;
    }
};
}
}