#include "../../unaryOperation.h"

class Sine: public UnaryOperation {
    public:
        Sine(std::shared_ptr<Expression> argument): UnaryOperation(argument) {}
        double evaluate(double x) const override {
            return sin(argument->evaluate(x));
        }
};