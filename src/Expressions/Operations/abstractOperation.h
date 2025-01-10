#pragma once
#include "../expression.h"
#include "strategyConfig.h"
#include "Strategies/operationStrategy.h"
#include <span>
#include <memory>

namespace ArithmeticPoints {
namespace Expressions {

template <typename Type>
class AbstractOperation : public Expression<Type> {
private:
    Strategies::StrategyConfig<Type> config;
    std::shared_ptr<Strategies::OperationStrategy<Type>> strategy;

public:
    AbstractOperation(std::shared_ptr<Strategies::OperationStrategy<Type>> strategy, const Strategies::StrategyConfig<Type>& config)
        :  strategy(std::move(strategy)), config(config) {}

    virtual void addTerm(std::shared_ptr<Expression<Type>> value) = 0;

    void setConfig(const Strategies::StrategyConfig<Type>& config) {
        this->config = std::move(config);
    }

    Strategies::StrategyConfig<Type> getConfig() const {
        return config;
    }

    std::shared_ptr<Strategies::OperationStrategy<Type>> getStrategy() const {
        return strategy;
    }
};

} // namespace Expressions
} // namespace ArithmeticPoints