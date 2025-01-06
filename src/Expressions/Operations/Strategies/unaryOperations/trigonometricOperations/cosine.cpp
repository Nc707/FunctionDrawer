#include "../../unaryOperation.h"

class Cosine: public UnaryOperation {
    public:
        Cosine(std::shared_ptr<Expression> argument): UnaryOperation(argument) {}
        double evaluate(double x) const override {
            return cos(argument->evaluate(x));
        }
};