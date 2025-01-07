#include "realExpressionFactory.h"


void RealExpressionFactory::registerStrategies() {
    registerStrategy("addition", std::make_shared<Addition<double>>());
    registerStrategy("subtraction", std::make_shared<Subtraction<double>>());
    registerStrategy("multiplication", std::make_shared<Multiplication<double>>());
    registerStrategy("division", std::make_shared<Division<double>>());
    registerStrategy("exponent", std::make_shared<Exponent<double>>());
    registerStrategy("logarithm", std::make_shared<Logarithm<double>>());
    //registerStrategy("negation", std::make_shared<Negation<double>>());
    registerStrategy("sine", std::make_shared<Sine<double>>());
    registerStrategy("cosine", std::make_shared<Cosine<double>>());
    registerStrategy("tangent", std::make_shared<Tangent<double>>());
}
 