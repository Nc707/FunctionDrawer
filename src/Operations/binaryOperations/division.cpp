#include <memory>
#include "../binaryOperation.h"

class Division: public BinaryOperation {
    public:
        Division(std::shared_ptr<Expression> leftOperator, std::shared_ptr<Expression> rightOperator): BinaryOperation(leftOperator, rightOperator) {}
        double evaluate(double x) const override {
            return izquierda->evaluate(x) + derecha->evaluate(x);
        }
};