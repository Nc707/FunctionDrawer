#pragma once
#include <cmath>
#include "../expression.h"



class UnaryOperation: public Expression {
    protected:
        std::shared_ptr<Expression> argument;
    public:
        UnaryOperation(std::shared_ptr<Expression> argument): argument(argument) {}
};