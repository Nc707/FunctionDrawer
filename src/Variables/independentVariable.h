#pragma once
#include <memory>
#include "variable.h"
#include "all-variables.h"
#include "../Operations/operations.h"


class IndependentVariable: public Variable {
    public:
        double evaluate(double x) const override {
            return x;
        }

    static IndependentVariable getInstance() {
        return *std::make_shared<IndependentVariable>();
    }
    
    std::shared_ptr<Expression> operator+(const std::shared_ptr<Expression>& other) const;
    std::shared_ptr<Expression> operator+(double other) const;

    std::shared_ptr<Expression> operator-(const std::shared_ptr<Expression>& other) const;
    std::shared_ptr<Expression> operator-(double other) const;

    std::shared_ptr<Expression> operator*(const std::shared_ptr<Expression>& other) const;
    std::shared_ptr<Expression> operator*(double other) const;
    
    std::shared_ptr<Expression> operator/(const std::shared_ptr<Expression>& other) const;
    std::shared_ptr<Expression> operator/(double other) const;

};