#pragma once
#include <memory>
#include "Factories/realExpressionFactory.h"

class var {
private:
    std::shared_ptr<Expression<double>> argument;
    static RealExpressionFactory factory;

public:
    var(std::shared_ptr<Expression<double>> argument) : argument(std::move(argument)) {}

    var() { argument = factory.createVariable(); }

    var(double value) : argument(factory.createConstant(value)) {}

    std::shared_ptr<Expression<double>> getArgument() const {
        return argument;
    }

    var log(const var& value) const {
        return var(factory.createBinaryOperation("logarithm", argument, value.argument));
    }

    var log(double value) const {
        return var(factory.createBinaryOperation("logarithm", argument, factory.createConstant(value)));
    }

    var operator+(const var& value) const {
        return var(factory.createBinaryOperation("addition", argument, value.argument));
    }

    var operator+(double value) const {
        return var(factory.createBinaryOperation("addition", argument, factory.createConstant(value)));
    }

    var operator-(const var& value) const {
        return var(factory.createBinaryOperation("subtraction", argument, value.argument));
    }

    var operator-(double value) const {
        return var(factory.createBinaryOperation("subtraction", argument, factory.createConstant(value)));
    }

    var operator*(const var& value) const {
        return var(factory.createBinaryOperation("multiplication", argument, value.argument));
    }

    var operator*(double value) const {
        return var(factory.createBinaryOperation("multiplication", argument, factory.createConstant(value)));
    }

    var operator/(const var& value) const {
        return var(factory.createBinaryOperation("division", argument, value.argument));
    }

    var operator/(double value) const {
        return var(factory.createBinaryOperation("division", argument, factory.createConstant(value)));
    }

    var operator^(const var& value) const {
        return var(factory.createBinaryOperation("exponent", argument, value.argument));
    }

    var operator^(double value) const {
        return var(factory.createBinaryOperation("exponent", argument, factory.createConstant(value)));
    }

    // Non-member function to handle var + double
    friend var operator+(double lhs, const var& rhs) {
        return var(factory.createBinaryOperation("addition", factory.createConstant(lhs), rhs.getArgument()));
    }

    // Non-member function to handle int + var
    friend var operator+(int lhs, const var& rhs) {
        return var(factory.createBinaryOperation("addition", factory.createConstant(static_cast<double>(lhs)), rhs.getArgument()));
    }

    // Non-member function to handle var - double
    friend var operator-(double lhs, const var& rhs) {
        return var(factory.createBinaryOperation("subtraction", factory.createConstant(lhs), rhs.getArgument()));
    }

    // Non-member function to handle int - var
    friend var operator-(int lhs, const var& rhs) {
        return var(factory.createBinaryOperation("subtraction", factory.createConstant(static_cast<double>(lhs)), rhs.getArgument()));
    }

    // Non-member function to handle var * double
    friend var operator*(double lhs, const var& rhs) {
        return var(factory.createBinaryOperation("multiplication", factory.createConstant(lhs), rhs.getArgument()));
    }

    // Non-member function to handle int * var
    friend var operator*(int lhs, const var& rhs) {
        return var(factory.createBinaryOperation("multiplication", factory.createConstant(static_cast<double>(lhs)), rhs.getArgument()));
    }

    // Non-member function to handle var / double
    friend var operator/(double lhs, const var& rhs) {
        return var(factory.createBinaryOperation("division", factory.createConstant(lhs), rhs.getArgument()));
    }

    // Non-member function to handle int / var
    friend var operator/(int lhs, const var& rhs) {
        return var(factory.createBinaryOperation("division", factory.createConstant(static_cast<double>(lhs)), rhs.getArgument()));
    }

    // Non-member function to handle double ^ var
    friend var operator^(double lhs, const var& rhs) {
        return var(factory.createBinaryOperation("exponent", factory.createConstant(lhs), rhs.getArgument()));
    }

    // Non-member function to handle int ^ var
    friend var operator^(int lhs, const var& rhs) {
        return var(factory.createBinaryOperation("exponent", factory.createConstant(static_cast<double>(lhs)), rhs.getArgument()));
    }

    // Non-member function to handle sin(var)
    friend var sin(const var& value) {
        return var(factory.createUnaryOperation("sine", value.argument));
    }

    // Non-member function to handle cos(var)
    friend var cos(const var& value) {
        return var(factory.createUnaryOperation("cosine", value.argument));
    }

    // Non-member function to handle tan(var)
    friend var tan(const var& value) {
        return var(factory.createUnaryOperation("tangent", value.argument));
    }
};

// Define the static member
RealExpressionFactory var::factory;