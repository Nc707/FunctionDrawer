#include <memory>
#include "../binaryOperation.h"

class Logarithm: public BinaryOperation {
    public:
        Logarithm(std::shared_ptr<Expression> leftOperator, std::shared_ptr<Expression> rightOperator): BinaryOperation(leftOperator, rightOperator) {}
        double evaluate(double x) const override {
            try{
                return log(izquierda->evaluate(x)) / log(derecha->evaluate(x));
            } catch (std::invalid_argument&) {
                throw std::invalid_argument("The base and the argument must be positive.");
            }
        }
};