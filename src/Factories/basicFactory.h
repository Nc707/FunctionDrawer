#pragma once

#include "abstractExpressionsFactory.h"
#include "../Expressions/all_expressions.h"
#include <sstream>

namespace ArithmeticPoints{
namespace Factories{
namespace ST = Strategies;
template <typename Type>
class BasicFactory: public AbstractExpressionsFactory<Type> {
public:
    BasicFactory() {
        registerStrategies();
    }

    void registerStrategies() override {
    this->registerStrategy("addition", std::make_shared<ST::Addition<Type>>());
    this->registerStrategy("subtraction", std::make_shared<ST::Subtraction<Type>>());
    this->registerStrategy("multiplication", std::make_shared<ST::Multiplication<Type>>());
    this->registerStrategy("division", std::make_shared<ST::Division<Type>>());
    this->registerStrategy("exponent", std::make_shared<ST::Exponent<Type>>());
    this->registerStrategy("logarithm", std::make_shared<ST::Logarithm<Type>>());
    this->registerStrategy("negation", std::make_shared<ST::Negation<Type>>());
    this->registerStrategy("sine", std::make_shared<ST::Sine<Type>>());
    this->registerStrategy("cosine", std::make_shared<ST::Cosine<Type>>());
    this->registerStrategy("tangent", std::make_shared<ST::Tangent<Type>>());

    this->registerConfig("default", ST::StrategyConfig<Type>());

    }

    std::string getAvailableStrategyTypes() const override{
    std::ostringstream result;
    for (const auto& [key, value] : this->strategyCreators) {
        result << key << " ";
    }
    return result.str();
    }

    std::string getAvailableStrategyConfigs() const override{
        std::ostringstream result;
        for (const auto& [key, value] : AbstractExpressionsFactory<Type>::strategyConfigs) {
            result << key << " ";
        }
        return result.str();
    }
};
}
}