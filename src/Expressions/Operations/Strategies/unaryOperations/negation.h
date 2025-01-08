#include "unaryStrategy.h"

namespace ArithmeticPoints{
namespace Strategies{
template <typename Type>
class Negation: UnaryStrategy<Type> {
    public:
        Type evaluate(const Type& argument) const override {
            return -argument;
        }
};
}
}