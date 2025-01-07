#include "../Point2DGenerator.h"

template <typename Type>
class Basic2DGenerator : public Point2DGenerator<Type> {
public:
    Basic2DGenerator(std::shared_ptr<Expression<Type>> expr) : Point2DGenerator<Type>(std::move(expr)) {}

    std::vector<std::tuple<double, double>> generatePoints(axisData<Type> data) const override {
        std::vector<std::tuple<double, double>> points;
        for (Type x = data.axisBase; x <= data.axisTop; x += data.step) {
            Type y = this->getExpression()->evaluate(x);
            points.emplace_back(x, y);
        }
        return points;
    }
};