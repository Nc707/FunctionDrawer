#include "basicFactory.h"

namespace ArithmeticPoints{
namespace Factories{
namespace ST = Strategies;

template <typename Type>
void BasicFactory<Type>::registerStrategies() {
    registerStrategy("addition", std::make_shared<ST::Addition<double>>());
    registerStrategy("subtraction", std::make_shared<ST::Subtraction<double>>());
    registerStrategy("multiplication", std::make_shared<ST::Multiplication<double>>());
    registerStrategy("division", std::make_shared<ST::Division<double>>());
    registerStrategy("exponent", std::make_shared<ST::Exponent<double>>());
    registerStrategy("logarithm", std::make_shared<ST::Logarithm<double>>());
    //registerStrategy("negation", std::make_shared<Negation<double>>());
    registerStrategy("sine", std::make_shared<ST::Sine<double>>());
    registerStrategy("cosine", std::make_shared<ST::Cosine<double>>());
    registerStrategy("tangent", std::make_shared<ST::Tangent<double>>());

}

template class BasicFactory<double>;

}
}