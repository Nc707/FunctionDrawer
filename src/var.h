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

        var(){argument = std::make_shared<RealIndependentVariable>();};

        var(double value): argument(std::make_shared<RealConstant>(value)) {}

        std::shared_ptr<Expression> getArgument() const {
            return argument;
        }

        var log(const var& value) const {
            return var(std::make_shared<Logarithm>(argument, value.argument));
        }

        var log(double value) const {
            return var(std::make_shared<Logarithm>(argument, std::make_shared<RealConstant>(value)));
        }
        /*
        friend var log(const var& value) {
            return var(std::make_shared<Logarithm>(std::make_shared<RealConstant>(M_E), value.argument));
        }*/

        
        var operator+(const var& value) const {
            return var(std::make_shared<Addition>(argument, value.argument));
        }

        var operator+(double value) const {
            return var(std::make_shared<Addition>(argument, std::make_shared<RealConstant>(value)));
        }

        var operator-(const var& value) const {
            return var(std::make_shared<Substraction>(argument, value.argument));
        }

        var operator-(double value) const {
            return var(std::make_shared<Substraction>(argument, std::make_shared<RealConstant>(value)));
        }

        var operator*(const var& value) const {
            return var(std::make_shared<Multiplication>(argument, value.argument));
        }

        var operator*(double value) const {
            return var(std::make_shared<Multiplication>(argument, std::make_shared<RealConstant>(value)));
        }

        var operator/(const var& value) const {
            return var(std::make_shared<Division>(argument, value.argument));
        }

        var operator/(double value) const {
            return var(std::make_shared<Division>(argument, std::make_shared<RealConstant>(value)));
        }

        var operator^(const var& value) const {
            return var(std::make_shared<Exponent>(argument, value.argument));
        }

        var operator^(double value) const {
            return var(std::make_shared<Exponent>(argument, std::make_shared<RealConstant>(value)));
        }
        
        // Non-member function to handle var + double
        friend var operator+(double lhs, const var& rhs) {
            return var(std::make_shared<Addition>(std::make_shared<RealConstant>(lhs), rhs.getArgument()));
        }
        
        // Non-member function to handle int + var
        friend var operator+(int lhs, const var& rhs) {
            return var(std::make_shared<Addition>(std::make_shared<RealConstant>(static_cast<double>(lhs)), rhs.getArgument()));
        }

        // Non-member function to handle var - double
        friend var operator-(double lhs, const var& rhs) {
            return var(std::make_shared<Substraction>(std::make_shared<RealConstant>(lhs), rhs.getArgument()));
        }

        // Non-member function to handle int - var
        friend var operator-(int lhs, const var& rhs) {
            return var(std::make_shared<Substraction>(std::make_shared<RealConstant>(static_cast<double>(lhs)), rhs.getArgument()));
        }

        // Non-member function to handle var * double
        friend var operator*(double lhs, const var& rhs) {
            return var(std::make_shared<Multiplication>(std::make_shared<RealConstant>(lhs), rhs.getArgument()));
        }

        // Non-member function to handle int * var
        friend var operator*(int lhs, const var& rhs) {
            return var(std::make_shared<Multiplication>(std::make_shared<RealConstant>(static_cast<double>(lhs)), rhs.getArgument()));
        }

        // Non-member function to handle var / double
        friend var operator/(double lhs, const var& rhs) {
            return var(std::make_shared<Division>(std::make_shared<RealConstant>(lhs), rhs.getArgument()));
        }

        // Non-member function to handle int / var
        friend var operator/(int lhs, const var& rhs) {
            return var(std::make_shared<Division>(std::make_shared<RealConstant>(static_cast<double>(lhs)), rhs.getArgument()));
        }

        // Non-member function to handle double ^ var
        friend var operator^(double lhs, const var& rhs) {
            return var(std::make_shared<Exponent>(std::make_shared<RealConstant>(lhs), rhs.getArgument()));
        }

        // Non-member function to handle int ^ var
        friend var operator^(int lhs, const var& rhs) {
            return var(std::make_shared<Exponent>(std::make_shared<RealConstant>(static_cast<double>(lhs)), rhs.getArgument()));
        }

        // Non-member function to handle sin(var)
        friend var sin(const var& value) {
            return var(std::make_shared<Sine>(value.argument));
        }

        // Non-member function to handle cos(var)
        friend var cos(const var& value) {
            return var(std::make_shared<Cosine>(value.argument));
        }

        // Non-member function to handle tan(var)
        friend var tan(const var& value) {
            return var(std::make_shared<Tangent>(value.argument));
        }


};



