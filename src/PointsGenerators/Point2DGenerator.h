#pragma once
#include <vector>
#include "../Expressions/expression.h"
#include "axisData.h"

namespace ArithmeticPoints{
namespace PointGeneration{

template <typename Type>
class Point2DGenerator {
private:
    std::shared_ptr<Expressions::Expression<Type>> expression;
public:
    Point2DGenerator(std::shared_ptr<Expressions::Expression<Type>> expr) : expression(std::move(expr)) {}

    std::shared_ptr<Expressions::Expression<Type>> getExpression() const {
        return expression;
    }

    virtual std::vector<std::tuple<double, double>> generatePoints(axisData<Type> data) const = 0;
};
    
}
}