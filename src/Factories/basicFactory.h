#pragma once

#include "abstractExpressionsFactory.h"
#include <sstream>

namespace ArithmeticPoints{
namespace Factories{

template <typename Type>
class BasicFactory: public AbstractExpressionsFactory<Type> {
public:
    BasicFactory() {
        registerStrategies();
    }

    void registerStrategies() override;

    // Creates an operation expression using the specified operation and strategy types.
    // The operationCreators map stores functions that create operation expressions.
    std::shared_ptr<Expressions::Expression<Type>> createUnaryOperation(const std::string& strategyType,
    const std::shared_ptr<Expressions::Expression<Type>>& argument) {
        std::shared_ptr<Strategies::OperationStrategy<Type>> strategy = findStrategy(strategyType);
        verifyArities(strategy->getArity(), Expressions::UnaryOperation<Type>::getArity());
        return std::make_shared<Expressions::UnaryOperation<Type>>(argument, strategy);
    }

    std::shared_ptr<Expressions::Expression<Type>> createBinaryOperation(const std::string& strategyType,
    const std::shared_ptr<Expressions::Expression<Type>>& left,
    const std::shared_ptr<Expressions::Expression<Type>>& right) {
        std::shared_ptr<Strategies::OperationStrategy<Type>> strategy = findStrategy(strategyType);
        verifyArities(strategy->getArity(), Expressions::BinaryOperation<Type>::getArity());
        return std::make_shared<Expressions::BinaryOperation<Type>>(left, right, strategy);
    }

    std::string getAvailableStrategyTypes() const override{
        std::ostringstream result;
        for (const auto& [key, value] : strategyCreators) {
            result << key << " ";
        }
        return result.str();
    }
protected:
    void verifyArities(int firstArity, int secondArity) const {
        if(firstArity != secondArity)
            throw std::invalid_argument("Arities do not match.");
    }

    std::shared_ptr<Strategies::OperationStrategy<Type>> findStrategy(const std::string& strategyType) {
        auto it = strategyCreators.find(strategyType);
        if(it == strategyCreators.end())
            throw std::invalid_argument("Unknown strategy type: " + strategyType + "\n" +
            "Available strategy types: " + getAvailableStrategyTypes());
        else    return it->second();
    }
};
}
}

#include "basicFactoryStrategies.h"