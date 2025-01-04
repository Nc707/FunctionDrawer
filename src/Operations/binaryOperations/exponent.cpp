#include <memory>
#include "../binaryOperation.h"

class Exponent: public BinaryOperation {
    public:
        Exponent(std::shared_ptr<Expression> leftOperator, std::shared_ptr<Expression> rightOperator): BinaryOperation(leftOperator, rightOperator) {}
        double evaluate(double x) const override {
            try{
                return pow(izquierda->evaluate(x), derecha->evaluate(x));
            } catch (std::invalid_argument&) {
                throw std::invalid_argument("The base and the exponent must be positive.");
            }
        }
};