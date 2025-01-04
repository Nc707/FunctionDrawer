#pragma once
#include <stdexcept>
#include "../expression.h"

class Variable: public Expression {
    public:
        virtual ~Variable() = default;
};