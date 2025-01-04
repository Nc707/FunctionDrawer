#include "../../unaryOperation.h"

class Tangent: public UnaryOperation {
    public:
        Tangent(std::shared_ptr<Expression> argument): UnaryOperation(argument) {}
        double evaluate(double x) const override {
            return tan(argument->evaluate(x));
        }
};