#pragma once
#include <set>
#include <stdexcept>
#include <memory>

namespace ArithmeticPoints {

template <typename Type>
class Interval {
public:
    virtual Type getLowerBound() const = 0;
    virtual Type getUpperBound() const = 0;
    virtual bool isLowerClosed() const = 0;
    virtual bool isUpperClosed() const = 0;
    virtual bool isLowerInfinite() const = 0;
    virtual bool isUpperInfinite() const = 0;
    virtual bool contains(Type value) const = 0;
    virtual bool contains(const std::shared_ptr<Interval<Type>>& other) const = 0;
    virtual bool intersects(const std::shared_ptr<Interval<Type>>& other) const = 0;
    virtual std::shared_ptr<Interval<Type>> intersection(const std::shared_ptr<Interval<Type>>& other) const = 0;
    virtual std::shared_ptr<Interval<Type>> joint(const std::shared_ptr<Interval<Type>>& other) const = 0;
    virtual bool isDiscrete() const = 0;
    virtual bool isContinuous() const = 0;
    virtual bool isFinite() const = 0;
    virtual bool isInfinite() const = 0;
    virtual bool isEmpty() const = 0;

    // Default implementations for methods that may not apply to all intervals
    virtual void addSubInterval(std::shared_ptr<Interval<Type>> interval) {
        throw std::logic_error("addSubInterval not supported for this interval type");
    }

    virtual void flatten() {
        throw std::logic_error("flatten not supported for this interval type");
    }

    virtual bool isLeaf() const {
        return false;
    }

    virtual std::set<std::shared_ptr<Interval<Type>>> getSubIntervals() const {
        return std::set<std::shared_ptr<Interval<Type>>>();
    }

    virtual ~Interval() = default;
};

} // namespace ArithmeticPoints