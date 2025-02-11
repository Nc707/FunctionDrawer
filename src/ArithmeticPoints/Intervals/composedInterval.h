#pragma once
#include "interval.h"

namespace ArithmeticPoints {

template <typename Type>
class ComposedInterval : public Interval<Type> {
private:
    std::set<std::shared_ptr<Interval<Type>>> subIntervals;

public:
    Type getLowerBound() const override {
        return subIntervals.begin()->get()->getLowerBound();
    }

    Type getUpperBound() const override {
        return subIntervals.rbegin()->get()->getUpperBound();
    }

    bool isLowerClosed() const override {
        return subIntervals.begin()->get()->isLowerClosed();
    }

    bool isUpperClosed() const override {
        return subIntervals.rbegin()->get()->isUpperClosed();
    }

    bool isLowerInfinite() const override {
        return subIntervals.begin()->get()->isLowerInfinite();
    }

    bool isUpperInfinite() const override {
        return subIntervals.rbegin()->get()->isUpperInfinite();
    }

    bool contains(Type value) const override {
        for (const auto& interval : subIntervals) {
            if (interval->contains(value)) {
                return true;
            }
        }
        return false;
    }

    bool contains(const Interval<Type>& other) const override {
        for (const auto& interval : subIntervals) {
            if (interval->contains(other)) {
                return true;
            }
        }
        return false;
    }

    bool intersects(const Interval<Type>& other) const override {
        for (const auto& interval : subIntervals) {
            if (interval->intersects(other)) {
                return true;
            }
        }
        return false;
    }

    std::shared_ptr<Interval<Type>> intersection(const std::shared_ptr<Interval<Type>>& other) const override {
        for (const auto& interval : subIntervals) {
            if (interval->intersects(*other)) {
                return interval->intersection(other);
            }
        }
        return std::make_shared<ComposedInterval<Type>>();
    }

    std::shared_ptr<Interval<Type>> joint(const std::shared_ptr<Interval<Type>>& other) const override {
        for (const auto& interval : subIntervals) {
            if (interval->intersects(*other)) {
                return interval->joint(other);
            }
        }
        return std::make_shared<ComposedInterval<Type>>();
    }

    bool isDiscrete() const override {
        for (const auto& interval : subIntervals) {
            if (interval->isContinuous()) {
                return false;
            }
        }
        return true;
    }

    bool isContinuous() const override {
        for (const auto& interval : subIntervals) {
            if (interval->isContinuous()) {
                return true;
            }
        }
        return false;
    }

    bool isFinite() const override {
        for (const auto& interval : subIntervals) {
            if (interval->isInfinite()) {
                return false;
            }
        }
        return true;
    }

    bool isInfinite() const override {
        for (const auto& interval : subIntervals) {
            if (interval->isInfinite()) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() const override {
        return subIntervals.empty();
    }

    void addSubInterval(std::shared_ptr<Interval<Type>> interval) override {
        for (auto it = subIntervals.begin(); it != subIntervals.end(); ) {
            if ((*it)->intersects(*interval)) {
                interval = (*it)->joint(interval);
                it = subIntervals.erase(it);
            } else {
                ++it;
            }
        }
        subIntervals.insert(std::move(interval));
        this->flatten();
    }

    void flatten() override {
        std::set<std::shared_ptr<Interval<Type>>> newSubIntervals;
        for (auto& interval : subIntervals) {
            if (!interval->isLeaf()) {
                interval->flatten();
                for (auto& subInterval : interval->getSubIntervals()) {
                    newSubIntervals.insert(std::move(subInterval));
                }
            } else {
                newSubIntervals.insert(std::move(interval));
            }
        }
        subIntervals = std::move(newSubIntervals);
    }

    bool isLeaf() const override {
        return subIntervals.size() == 1 && subIntervals.begin()->get()->isLeaf();
    }

    std::set<std::shared_ptr<Interval<Type>>> getSubIntervals() const override {
        std::set<std::shared_ptr<Interval<Type>>> copy;
        for (const auto& interval : subIntervals) {
            copy.insert(interval->clone());
        }
        return copy;
    }
};

} // namespace ArithmeticPoints