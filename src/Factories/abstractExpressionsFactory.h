#pragma once
#include "../Expressions/all_expressions.h"
#include <memory>
#include <unordered_map>
#include <functional>
namespace ArithmeticPoints{
namespace Factories{
template <typename Type>
class AbstractExpressionsFactory {
public:
    using StrategyCreator = std::function<std::shared_ptr<Strategies::OperationStrategy<Type>>()>;// A function that creates a strategy.

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

protected:
    std::unordered_map<std::string, StrategyCreator> strategyCreators;
    // Registers a strategy with the given type.
    // @param strategyType: The type of the strategy to register.
    // @param strategy: A shared pointer to the strategy to register.
    void registerStrategy(const std::string& strategyType,std::shared_ptr<Strategies::OperationStrategy<Type>> strategy) {
        strategyCreators[strategyType] = [strategy]() -> std::shared_ptr<Strategies::OperationStrategy<Type>> {
            return strategy;
        };
    }
    
};
}
}