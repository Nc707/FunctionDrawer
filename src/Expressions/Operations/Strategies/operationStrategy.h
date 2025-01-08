#pragma once

namespace ArithmeticPoints{
namespace Strategies{
template<typename Type>
class OperationStrategy {
public:
    virtual Type evaluate(const Type& left, const Type& right) const = 0;
    virtual Type evaluate(const Type& value) const = 0;
    virtual int getArity() const = 0;
};
}
}