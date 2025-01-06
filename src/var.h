#pragma once
#include <memory>
#include "Expressions/all_expressions.h"

class var {
private:
    std::shared_ptr<Expression<double>> argument;

public:
    var(std::shared_ptr<Expression<double>> argument) : argument(std::move(argument)) {}

    var() { argument = std::make_shared<IndependentVariable<double>>(); }

    var(double value) : argument(std::make_shared<Constant<double>>(value)) {}

    std::shared_ptr<Expression<double>> getArgument() const {
        return argument;
    }

    var log(const var& value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, value.argument, std::make_shared<Logarithm<double>>()));
    }

    var log(double value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, std::make_shared<Constant<double>>(value), std::make_shared<Logarithm<double>>()));
    }

    var operator+(const var& value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, value.argument, std::make_shared<Addition<double>>()));
    }

    var operator+(double value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, std::make_shared<Constant<double>>(value), std::make_shared<Addition<double>>()));
    }

    var operator-(const var& value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, value.argument, std::make_shared<Substraction<double>>()));
    }

    var operator-(double value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, std::make_shared<Constant<double>>(value), std::make_shared<Substraction<double>>()));
    }

    var operator*(const var& value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, value.argument, std::make_shared<Multiplication<double>>()));
    }

    var operator*(double value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, std::make_shared<Constant<double>>(value), std::make_shared<Multiplication<double>>()));
    }

    var operator/(const var& value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, value.argument, std::make_shared<Division<double>>()));
    }

    var operator/(double value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, std::make_shared<Constant<double>>(value), std::make_shared<Division<double>>()));
    }

    var operator^(const var& value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, value.argument, std::make_shared<Exponent<double>>()));
    }

    var operator^(double value) const {
        return var(std::make_shared<BinaryOperation<double>>(argument, std::make_shared<Constant<double>>(value), std::make_shared<Exponent<double>>()));
    }

    // Non-member function to handle var + double
    friend var operator+(double lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(lhs), rhs.getArgument(), std::make_shared<Addition<double>>()));
    }

    // Non-member function to handle int + var
    friend var operator+(int lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(static_cast<double>(lhs)), rhs.getArgument(), std::make_shared<Addition<double>>()));
    }

    // Non-member function to handle var - double
    friend var operator-(double lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(lhs), rhs.getArgument(), std::make_shared<Substraction<double>>()));
    }

    // Non-member function to handle int - var
    friend var operator-(int lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(static_cast<double>(lhs)), rhs.getArgument(), std::make_shared<Substraction<double>>()));
    }

    // Non-member function to handle var * double
    friend var operator*(double lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(lhs), rhs.getArgument(), std::make_shared<Multiplication<double>>()));
    }

    // Non-member function to handle int * var
    friend var operator*(int lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(static_cast<double>(lhs)), rhs.getArgument(), std::make_shared<Multiplication<double>>()));
    }

    // Non-member function to handle var / double
    friend var operator/(double lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(lhs), rhs.getArgument(), std::make_shared<Division<double>>()));
    }

    // Non-member function to handle int / var
    friend var operator/(int lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(static_cast<double>(lhs)), rhs.getArgument(), std::make_shared<Division<double>>()));
    }

    // Non-member function to handle double ^ var
    friend var operator^(double lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(lhs), rhs.getArgument(), std::make_shared<Exponent<double>>()));
    }

    // Non-member function to handle int ^ var
    friend var operator^(int lhs, const var& rhs) {
        return var(std::make_shared<BinaryOperation<double>>(std::make_shared<Constant<double>>(static_cast<double>(lhs)), rhs.getArgument(), std::make_shared<Exponent<double>>()));
    }

    // Non-member function to handle sin(var)
    friend var sin(const var& value) {
        return var(std::make_shared<UnaryOperation<double>>(value.argument, std::make_shared<Sine<double>>()));
    }

    // Non-member function to handle cos(var)
    friend var cos(const var& value) {
        return var(std::make_shared<UnaryOperation<double>>(value.argument, std::make_shared<Cosine<double>>()));
    }

    // Non-member function to handle tan(var)
    friend var tan(const var& value) {
        return var(std::make_shared<UnaryOperation<double>>(value.argument, std::make_shared<Tangent<double>>()));
    }
};
