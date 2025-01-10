#pragma once
#include <memory>
#include <stdexcept>
#include "../Expressions/expression.h"
#include "../Factories/basicFactory.h"

namespace ArithmeticPoints {

template <typename Type>
class BasicExpressionVariable {
private:
    std::shared_ptr<Expressions::Expression<Type>> argument;
    static Factories::BasicFactory<Type> factory;

public:
    BasicExpressionVariable(std::shared_ptr<Expressions::Expression<Type>> argument) : argument(std::move(argument)) {}
    BasicExpressionVariable() { argument = factory.createVariable(); }
    BasicExpressionVariable(Type value) : argument(factory.createConstant(value)) {}

    std::shared_ptr<Expressions::Expression<Type>> getArgument() const {
        return argument;
    }

    // Overloaded operators
    BasicExpressionVariable<Type> operator+(const BasicExpressionVariable<Type>& rhs) const {
        auto operation = factory.createOrAppendOperation("addition", "default", argument, rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator+(Type rhs) const {
        auto operation = factory.createOrAppendOperation("addition", "default", argument, factory.createConstant(rhs));
        return BasicExpressionVariable<Type>(operation);
    }
    BasicExpressionVariable<Type> operator-(const BasicExpressionVariable<Type>& rhs) const {
        auto operation = factory.createOrAppendOperation("subtraction", "default", argument, rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator-(Type rhs) const {
        auto operation = factory.createOrAppendOperation("subtraction", "default", argument, factory.createConstant(rhs));
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator*(const BasicExpressionVariable<Type>& rhs) const {
        auto operation = factory.createOrAppendOperation("multiplication", "default", argument, rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator*(Type rhs) const {
        auto operation = factory.createOrAppendOperation("multiplication", "default", argument, factory.createConstant(rhs));
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator/(const BasicExpressionVariable<Type>& rhs) const {
        auto operation = factory.createOrAppendOperation("division", "default", argument, rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator/(Type rhs) const {
        auto operation = factory.createOrAppendOperation("division", "default", argument, factory.createConstant(rhs));
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator^(const BasicExpressionVariable<Type>& rhs) const {
        auto operation = factory.createOrAppendOperation("exponent", "default", argument, rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    BasicExpressionVariable<Type> operator^(Type rhs) const {
        auto operation = factory.createOrAppendOperation("exponent", "default", argument, factory.createConstant(rhs));
        return BasicExpressionVariable<Type>(operation);
    }

    // Friend functions for unary operations
    friend BasicExpressionVariable<Type> sin(const BasicExpressionVariable<Type>& value) {
        auto operation = factory.createOperation("sine", "default", {value.getArgument()});
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> cos(const BasicExpressionVariable<Type>& value) {
        auto operation = factory.createOperation("cosine", "default", {value.getArgument()});
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> tan(const BasicExpressionVariable<Type>& value) {
        auto operation = factory.createOperation("tangent", "default", {value.getArgument()});
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> operator-(const BasicExpressionVariable<Type>& value) {
        auto operation = factory.createOperation("negation", "default", {value.getArgument()});
        return BasicExpressionVariable<Type>(operation);
    }

    // Friend functions for binary operations with non-BasicExpressionVariable first term
    friend BasicExpressionVariable<Type> operator+(Type lhs, const BasicExpressionVariable<Type>& rhs) {
        auto operation = factory.createOrAppendOperation("addition", "default", factory.createConstant(lhs), rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> operator-(Type lhs, const BasicExpressionVariable<Type>& rhs) {
        auto operation = factory.createOrAppendOperation("subtraction", "default", factory.createConstant(lhs), rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> operator*(Type lhs, const BasicExpressionVariable<Type>& rhs) {
        auto operation = factory.createOrAppendOperation("multiplication", "default", factory.createConstant(lhs), rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> operator/(Type lhs, const BasicExpressionVariable<Type>& rhs) {
        auto operation = factory.createOrAppendOperation("division", "default", factory.createConstant(lhs), rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> operator^(Type lhs, const BasicExpressionVariable<Type>& rhs) {
        auto operation = factory.createOrAppendOperation("exponent", "default", factory.createConstant(lhs), rhs.getArgument());
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> log(const BasicExpressionVariable<Type>& lhs, const BasicExpressionVariable<Type>& rhs) {
        auto operation = factory.createOperation("logarithm", "default", {lhs.getArgument(), rhs.getArgument()});
        return BasicExpressionVariable<Type>(operation);
    }

    friend BasicExpressionVariable<Type> log(const BasicExpressionVariable<Type>& lhs, double rhs) {
        auto operation = factory.createOperation("logarithm", "default", {lhs.getArgument(), factory.createConstant(rhs)});
        return BasicExpressionVariable<Type>(operation);
    }
};

template <typename Type>
Factories::BasicFactory<Type> BasicExpressionVariable<Type>::factory;

} // namespace ArithmeticPoints