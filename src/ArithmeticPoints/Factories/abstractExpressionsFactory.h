#pragma once
#include <memory>
#include <unordered_map>
#include <functional>
#include <span>
#include "../Expressions/expression.h"
#include "../Expressions/Variables/Constants/constant.h"
#include "../Expressions/Variables/IndependentVariables/independentVariable.h"
#include "../Expressions/Operations/Strategies/operationStrategy.h"
#include "../Expressions/Operations/strategyConfig.h"
#include "../Expressions/Operations/abstractOperation.h"
#include "../Expressions/Operations/operation.h"

namespace ArithmeticPoints {
namespace Factories {

template <typename Type>
class AbstractExpressionsFactory {
public:
    using StrategyCreator = std::function<std::shared_ptr<Strategies::OperationStrategy<Type>>()>; // A function that creates a strategy.
    using StrategyConfig = Strategies::StrategyConfig<Type>; // A configuration for a strategy.

    virtual void registerStrategies() = 0;

    // Creates a constant expression with the specified value.
    // This method returns a shared pointer to a Constant expression.
    std::shared_ptr<Expressions::Expression<Type>> createConstant(Type value) {
        return std::make_shared<Expressions::Constant<Type>>(value);
    }
    
    // Creates a variable expression.
    // This method returns a shared pointer to an IndependentVariable expression.
    std::shared_ptr<Expressions::Expression<Type>> createVariable() {
        return std::make_shared<Expressions::IndependentVariable<Type>>();
    }

    virtual std::string getAvailableStrategyTypes() const = 0;

    virtual std::string getAvailableStrategyConfigs() const = 0;

    virtual std::shared_ptr<Expressions::Expression<Type>> createOperation(const std::string& strategyType, const std::string& configType,
    std::initializer_list<std::shared_ptr<Expressions::Expression<Type>>> operands) {
        auto strategyIt = strategyCreators.find(strategyType);
        if (strategyIt == strategyCreators.end()) {
            throw std::invalid_argument("Unknown strategy type: " + strategyType);
        }

        auto configIt = strategyConfigs.find(configType);
        if (configIt == strategyConfigs.end()) {
            throw std::invalid_argument("Unknown config type: " + configType);
        }

        auto strategy = strategyIt->second();
        auto config = configIt->second;

        auto operation = std::make_shared<Expressions::Operation<Type>>(strategy, config);
        for (const auto& operand : operands) {
            operation->addTerm(operand);
        }

        return operation;
    }

    std::shared_ptr<Expressions::Expression<Type>> createOrAppendOperation(
        const std::string& strategyType,
        const std::string& configType,
        std::shared_ptr<Expressions::Expression<Type>> left,
        std::shared_ptr<Expressions::Expression<Type>> right) {
        auto it = strategyCreators.find(strategyType);
        if (it == strategyCreators.end()) {
            throw std::invalid_argument("Unknown strategy type: " + strategyType);
        }
        auto strategy = it->second();
        auto configIt = strategyConfigs.find(configType);
        if (configIt == strategyConfigs.end()) {
            throw std::invalid_argument("Unknown config type: " + configType);
        }
        const auto& config = configIt->second;

        if (auto operation = std::dynamic_pointer_cast<Expressions::Operation<Type>>(left)) {
            if (getStrategyType(operation) == strategyType) {
                operation->addTerm(right);
                return operation;
            }
            if(right != nullptr) {
                auto newOperation = createOperation(strategyType, configType, {left, right});
                return newOperation;
            }else {
                auto newOperation = createOperation(strategyType, configType, {left});
                return newOperation;
            }

        }else if (left!= nullptr){
            if(right != nullptr) {
                auto newOperation = createOperation(strategyType, configType, {left, right});
                return newOperation;
            }else {
                auto newOperation = createOperation(strategyType, configType, {left});
                return newOperation;
            }
        }
        return createOperation(strategyType, configType, {});

    }

protected:
    std::unordered_map<std::string, StrategyCreator> strategyCreators;
    std::unordered_map<std::string, StrategyConfig> strategyConfigs;

    std::string getStrategyType(const std::shared_ptr<Expressions::Operation<Type>>& operation) const {
        for (const auto& [type, creator] : strategyCreators) {
            if (typeid(creator()).name() == typeid(operation->getStrategy()).name()) {
                return type;
            }
        }
        throw std::invalid_argument("Unknown strategy type for the given operation.");
    }

    // Registers a strategy with the given type.
    // @param strategyType: The type of the strategy to register.
    // @param strategy: A shared pointer to the strategy to register.
    void registerStrategy(const std::string& strategyType, std::shared_ptr<Strategies::OperationStrategy<Type>> strategy) {
        strategyCreators[strategyType] = [strategy]() { return strategy; };
    }

    void registerConfig(const std::string& configType, const Strategies::StrategyConfig<Type>& config) {
        strategyConfigs[configType] = config;
    }
};

} // namespace Factories
} // namespace ArithmeticPoints