#pragma once
#include <vector>
#include "../Expressions/expression.h"
#include "axisData.h"

template <typename Type>
struct planeData {
    axisData<Type> xData;
    axisData<Type> zData;
};

template <typename Type>
class Point3DGenerator {
private:
    std::shared_ptr<Expression<Type>> expression;
public:
    Point3DGenerator(std::shared_ptr<Expression<Type>> expr) : expression(std::move(expr)) {}

    std::shared_ptr<Expression<Type>> getExpression() const {
        return expression;
    }

    virtual std::vector<std::tuple<double, double, double>> generatePoints(volumeData data) const = 0;
};