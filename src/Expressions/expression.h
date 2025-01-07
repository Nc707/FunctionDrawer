#pragma once
#include <memory>

template <typename Type>
class Expression {
    public:
        virtual Type evaluate(Type x) const = 0;
        virtual ~Expression() = default;
        
};