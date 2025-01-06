#pragma once
#include <memory>

template <typename Type>
class Expression {
    public:
        virtual double evaluate(Type x) const = 0;
        virtual ~Expression() = default;
        
};