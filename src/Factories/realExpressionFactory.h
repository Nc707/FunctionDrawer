#pragma once

#include "basicFactory.h"
#include "../Expressions/all_expressions.h"

namespace ArithmeticPoints{
namespace Factories{
class RealExpressionFactory : public BasicFactory<double> {
public:
    RealExpressionFactory() {
        registerStrategies();
    }

    void registerStrategies() override;
};
}
}