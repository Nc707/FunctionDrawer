#include "unaryStrategy.h"

template <typename Type>
class negation: UnaryStrategy<Type> {
    public:
        double evaluate(const Type& argument) const override {
            return -argument;
        }
};