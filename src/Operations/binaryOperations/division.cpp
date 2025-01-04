#include <memory>
#include "../binaryOperation.h"

class Division: public BinaryOperation {
    public:
        Division(std::shared_ptr<Expression> leftOperator, std::shared_ptr<Expression> rightOperator): BinaryOperation(leftOperator, rightOperator) {}
        double evaluate(double x) const override {
            try{
                return izquierda->evaluate(x) / derecha->evaluate(x);
            } catch (std::invalid_argument&) {
                throw std::invalid_argument("The divisor must be different from zero.");
            }
        }
};