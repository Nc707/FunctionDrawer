#pragma once
#include <memory>
class Expression {
    public:
        virtual double evaluate(double x) const = 0;
        virtual ~Expression() = default;
        
};