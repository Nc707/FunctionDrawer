#pragma once

#include "abstractExpressionsFactory.h"
#include <sstream>

template <typename Type>
class BasicFactory: public AbstractExpressionsFactory<Type> {
public:
    // Creates an operation expression using the specified operation and strategy types.
    // The operationCreators map stores functions that create operation expressions.
    std::shared_ptr<Expression<Type>> createUnaryOperation(const std::string& strategyType, const std::shared_ptr<Expression<Type>>& argument) {
        std::shared_ptr<OperationStrategy<Type>> strategy = findStrategy(strategyType);
        verifyArities(strategy->getArity(), UnaryOperation<Type>::getArity());
        return std::make_shared<UnaryOperation<Type>>(argument, strategy);
    }

    std::shared_ptr<Expression<Type>> createBinaryOperation(const std::string& strategyType, const std::shared_ptr<Expression<Type>>& left, const std::shared_ptr<Expression<Type>>& right) {
        std::shared_ptr<OperationStrategy<Type>> strategy = findStrategy(strategyType);
        verifyArities(strategy->getArity(), BinaryOperation<Type>::getArity());
        return std::make_shared<BinaryOperation<Type>>(left, right, strategy);
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

    std::shared_ptr<OperationStrategy<Type>> findStrategy(const std::string& strategyType) {
        auto it = strategyCreators.find(strategyType);
        if(it == strategyCreators.end())
            throw std::invalid_argument("Unknown strategy type: " + strategyType + "\n" +
            "Available strategy types: " + getAvailableStrategyTypes());
        else    return it->second();
    }
};
