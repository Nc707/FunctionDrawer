#pragma once
#include <memory>
#include <vector>
#include "expression.h"

class Function {
    private:
        std::shared_ptr<Expression> argument;
    public:
        Function(std::shared_ptr<Expression> argument): argument(std::move(argument)) {}

    std::vector<std::pair<double, double>> generatePoints(double init, double end, double step) const {
        std::vector<std::pair<double, double>> points;
        for (double x = init; x <= end; x += step) {
            points.emplace_back(x, argument->evaluate(x));
        }
        return points;
    }
};