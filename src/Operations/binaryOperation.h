#pragma once
#include <stdexcept>
#include "../expression.h"
class BinaryOperation: public Expression {
    protected:
        std::shared_ptr<Expression> izquierda;
        std::shared_ptr<Expression> derecha;
    public:
        BinaryOperation(std::shared_ptr<Expression> izquierda, std::shared_ptr<Expression> derecha): izquierda(izquierda), derecha(derecha) {}
};