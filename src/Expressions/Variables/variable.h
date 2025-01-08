#pragma once
#include <stdexcept>
#include "../expression.h"
namespace ArithmeticPoints{
namespace Expressions{
template <typename Type>
class Variable: public Expression<Type> {
    public:
        virtual ~Variable() = default;
};
}
}