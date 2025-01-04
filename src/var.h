#pragma once
#include <memory>
#include "expression.h"
#include "Operations/operations.h"
#include "Variables/all-variables.h"

class var {
    private:
        std::shared_ptr<Expression> argument;
    public:
        var(std::shared_ptr<Expression> argument): argument(std::move(argument)) {}

        var(){argument = std::make_shared<IndependentVariable>();};

        var(double value): argument(std::make_shared<Constant>(value)) {}

        std::shared_ptr<Expression> getArgument() const {
            return argument;
        }

        var operator+(const var& value) const {
            return var(std::make_shared<Addition>(argument, value.argument));
        }

        var operator+(double value) const {
            return var(std::make_shared<Addition>(argument, std::make_shared<Constant>(value)));
        }

        var operator-(const var& value) const {
            return var(std::make_shared<Substraction>(argument, value.argument));
        }

        var operator-(double value) const {
            return var(std::make_shared<Substraction>(argument, std::make_shared<Constant>(value)));
        }

        var operator*(const var& value) const {
            return var(std::make_shared<Multiplication>(argument, value.argument));
        }

        var operator*(double value) const {
            return var(std::make_shared<Multiplication>(argument, std::make_shared<Constant>(value)));
        }

        var operator/(const var& value) const {
            return var(std::make_shared<Division>(argument, value.argument));
        }

        var operator/(double value) const {
            return var(std::make_shared<Division>(argument, std::make_shared<Constant>(value)));
        }
};