#include "../unaryOperation.h"

class negation: UnaryOperation {
    public:
        negation(std::shared_ptr<Expression> argument): UnaryOperation(argument) {}
        double evaluate(double x) const override {
            return -argument->evaluate(x);
        }
};