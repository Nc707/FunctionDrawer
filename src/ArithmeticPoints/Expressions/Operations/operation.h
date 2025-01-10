#pragma once
#include "Strategies/operationStrategy.h"
#include "../expression.h"
#include "abstractOperation.h"
#include <vector>
#include <memory>

namespace ArithmeticPoints {
namespace Expressions {

template <typename Type>
class Operation : public AbstractOperation<Type> {
private:
    std::vector<std::shared_ptr<Expression<Type>>> terms;

public:
    Operation(std::shared_ptr<Strategies::OperationStrategy<Type>> strategy, const Strategies::StrategyConfig<Type>& config)
        : AbstractOperation<Type>(strategy, config) {}

    void addTerm(std::shared_ptr<Expression<Type>> value) override {
        terms.push_back(std::move(value));
    }
    Type evaluate(const Type value) const override {
        std::shared_ptr<Strategies::OperationStrategy<Type>> strategy = this->getStrategy();
        if (strategy!=nullptr) {
            std::vector<Type> evaluatedTerms;
            for (const auto term : terms) {
                evaluatedTerms.push_back(term->evaluate(value));
            }
            return strategy->evaluate(evaluatedTerms, this->getConfig());
        }
        throw std::runtime_error("Strategy is not set");
    }
};

} // namespace Expressions
} // namespace ArithmeticPoints