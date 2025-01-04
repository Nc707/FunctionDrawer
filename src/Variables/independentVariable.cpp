#include "independentVariable.h"
/*
    std::shared_ptr<Expression> IndependentVariable::operator+(
        const Expression& value) const {
        return std::make_shared<Addition>(std::make_shared<Expression>(*this), value);
    }*/
    std::shared_ptr<Expression> IndependentVariable::operator+(
        const std::shared_ptr<Expression>& value) const {
        return std::make_shared<Addition>(std::make_shared<IndependentVariable>(*this), std::move(value));
    }
    std::shared_ptr<Expression> IndependentVariable::operator+(double value) const {
        return std::make_shared<Addition>(std::make_shared<IndependentVariable>(*this),
         std::make_shared<Constant>(value));
    }/*
    std::shared_ptr<Expression> IndependentVariable::operator-(
        const std::shared_ptr<Expression>& value) const {
        return std::make_shared<Substraction>(std::make_shared<Expression>(*this), value);
    }*/
    std::shared_ptr<Expression> IndependentVariable::operator-(
        const std::shared_ptr<Expression>& value) const {
        return std::make_shared<Substraction>(std::make_shared<IndependentVariable>(*this), std::move(value));
    }
    std::shared_ptr<Expression> IndependentVariable::operator-(double value) const {
        return std::make_shared<Substraction>(std::make_shared<IndependentVariable>(*this),
         std::make_shared<Constant>(value));
    }/*
    std::shared_ptr<Expression> IndependentVariable::operator*(
        const std::shared_ptr<Expression>& value) const {
        return std::make_shared<Multiplication>(std::make_shared<Expression>(*this), value);
    }*/
    std::shared_ptr<Expression> IndependentVariable::operator*(
        const std::shared_ptr<Expression>& value) const {
        return std::make_shared<Multiplication>(std::make_shared<IndependentVariable>(*this), std::move(value));
    }
    std::shared_ptr<Expression> IndependentVariable::operator*(double value) const {
        return std::make_shared<Multiplication>(std::make_shared<IndependentVariable>(*this),
         std::make_shared<Constant>(value));
    }
    std::shared_ptr<Expression> IndependentVariable::operator/(
        const std::shared_ptr<Expression>& value) const {
        return std::make_shared<Division>(std::make_shared<IndependentVariable>(*this), std::move(value));
    }
    std::shared_ptr<Expression> IndependentVariable::operator/(double value) const {
        return std::make_shared<Division>(std::make_shared<IndependentVariable>(*this),
         std::make_shared<Constant>(value));
    }
