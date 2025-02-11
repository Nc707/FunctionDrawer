#pragma once

#include "interval.h"

namespace ArithmeticPoints {
    
template <typename Type>
class BasicInterval : public Interval<Type> {
private:
    Type lowerBound;
    Type upperBound;
    bool lowerClosed;
    bool upperClosed;
    bool lowerInfinite;
    bool upperInfinite;

public:
    BasicInterval(Type lowerBound, Type upperBound) {
        setLowerBound(lowerBound);
        setUpperBound(upperBound);
        setLowerClosed(true);
        setUpperClosed(true);
        setLowerInfinite(false);
        setUpperInfinite(false);
    }

    BasicInterval(Type lowerBound, Type upperBound, bool lowerClosed, bool upperClosed) {
        setLowerBound(lowerBound);
        setUpperBound(upperBound);
        setLowerClosed(lowerClosed);
        setUpperClosed(upperClosed);
        setLowerInfinite(false);
        setUpperInfinite(false);
    }

    BasicInterval(Type lowerBound, Type upperBound, bool lowerClosed, bool upperClosed, bool lowerInfinite, bool upperInfinite) {
        setLowerBound(lowerBound);
        setUpperBound(upperBound);
        setLowerClosed(lowerClosed);
        setUpperClosed(upperClosed);
        setLowerInfinite(lowerInfinite);
        setUpperInfinite(upperInfinite);
    }

    BasicInterval(Type point) {
        setLowerBound(point);
        setUpperBound(point);
        setLowerClosed(true);
        setUpperClosed(true);
        setLowerInfinite(false);
        setUpperInfinite(false);
    }

    BasicInterval() {
        setLowerBound(0);
        setUpperBound(0);
        setLowerClosed(true);
        setUpperClosed(true);
        setLowerInfinite(false);
        setUpperInfinite(false);
    }

    Type getLowerBound() const override {
        return lowerBound;
    }

    Type getUpperBound() const override {
        return upperBound;
    }

    bool isLowerClosed() const override {
        return lowerClosed;
    }

    bool isUpperClosed() const override {
        return upperClosed;
    }

    bool isLowerInfinite() const override {
        return lowerInfinite;
    }

    bool isUpperInfinite() const override {
        return upperInfinite;
    }

    bool contains(Type value) const override {
        if (isInfinite()) {
            if (lowerInfinite) {
                return value < upperBound || (value == upperBound && upperClosed);
            } else {
                return value > lowerBound || (value == lowerBound && lowerClosed);
            }
        } else if (isDiscrete()) {
            return (value == lowerBound && (this->lowerClosed || this->upperClosed));
        } else if (value == lowerBound) {
            return this->lowerClosed;
        } else if (value == upperBound) {
            return this->upperClosed;
        } else {
            return (value > lowerBound && value < upperBound);
        }
    }

    bool contains(const std::shared_ptr<Interval<Type>>& other) const override {
        if (isInfinite()) {
            if (lowerInfinite) {
                return other->getUpperBound() < upperBound || (other->getUpperBound() == upperBound && upperClosed);
            } else {
                return other->getLowerBound() > lowerBound || (other->getLowerBound() == lowerBound && lowerClosed);
            }
        } else if (isDiscrete()) {
            return (other->getLowerBound() == lowerBound && (this->lowerClosed || this->upperClosed));
        } else if (other->getLowerBound() == lowerBound) {
            return this->lowerClosed;
        } else if (other->getUpperBound() == upperBound) {
            return this->upperClosed;
        } else {
            return (other->getLowerBound() > lowerBound && other->getUpperBound() < upperBound);
        }
    }

    bool intersects(const std::shared_ptr<Interval<Type>>& other) const override {
        if (isInfinite()) {
            if (lowerInfinite) {
                return other->getUpperBound() > lowerBound || (other->getUpperBound() == lowerBound && lowerClosed);
            } else {
                return other->getLowerBound() < upperBound || (other->getLowerBound() == upperBound && upperClosed);
            }
        } else if (isDiscrete()) {
            return (other->getLowerBound() == lowerBound && (this->lowerClosed || this->upperClosed));
        } else if (other->getLowerBound() == lowerBound) {
            return this->lowerClosed;
        } else if (other->getUpperBound() == upperBound) {
            return this->upperClosed;
        } else if(other->getLowerBound() > upperBound)
                return false;
        else if(other->getUpperBound() < lowerBound)
                return false;
        else
            return true;
        
    }

    std::shared_ptr<Interval<Type>> intersection(const std::shared_ptr<Interval<Type>>& other) const override {
        if (intersects(other)) {
            if (isInfinite()) {
                if (lowerInfinite) {
                    return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), upperBound, other->isLowerClosed(), upperClosed);
                } else {
                    return std::make_shared<BasicInterval<Type>>(lowerBound, other->getUpperBound(), lowerClosed, other->isUpperClosed());
                }
            } else if (isDiscrete()) {
                return std::make_shared<BasicInterval<Type>>(lowerBound, lowerBound, this->lowerClosed, this->upperClosed);
            } else if (other->getLowerBound() == lowerBound) {
                return std::make_shared<BasicInterval<Type>>(lowerBound, other->getUpperBound(), this->lowerClosed, other->isUpperClosed());
            } else if (other->getUpperBound() == upperBound) {
                return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), upperBound, other->isLowerClosed(), this->upperClosed);
            } else {
                if(other->getLowerBound() < lowerBound)
                    return std::make_shared<BasicInterval<Type>>(lowerBound, other->getUpperBound(), this->lowerClosed, other->isUpperClosed());
                else
                    return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), upperBound, other->isLowerClosed(), this->upperClosed);
            }
        } else {
            return std::make_shared<BasicInterval<Type>>();
        }
    }

    std::shared_ptr<Interval<Type>> joint(const std::shared_ptr<Interval<Type>>& other) const override {
        if (intersects(other)) {
            if (isInfinite()) {
                if (lowerInfinite) {
                    return std::make_shared<BasicInterval<Type>>(lowerBound, other->getUpperBound(), lowerClosed, other->isUpperClosed());
                } else {
                    return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), upperBound, other->isLowerClosed(), upperClosed);
                }
            } else if (isDiscrete()) {
                return std::make_shared<BasicInterval<Type>>(lowerBound, lowerBound, this->lowerClosed, this->upperClosed);
            } else if (other->getLowerBound() == lowerBound) {
                return std::make_shared<BasicInterval<Type>>(lowerBound, other->getUpperBound(), this->lowerClosed, other->isUpperClosed());
            } else if (other->getUpperBound() == upperBound) {
                return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), upperBound, other->isLowerClosed(), this->upperClosed);
            } else {
                if(other->getLowerBound() < lowerBound and other->getUpperBound() > upperBound)
                    return std::make_shared<BasicInterval<Type>>(lowerBound, upperBound, this->lowerClosed, this->upperClosed);
                else if(other->getLowerBound() > lowerBound and other->getUpperBound() < upperBound)
                    return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), other->getUpperBound(), other->isLowerClosed(), other->isUpperClosed());
                else if(other->getLowerBound() > lowerBound)
                    return std::make_shared<BasicInterval<Type>>(lowerBound, other->getUpperBound(), this->lowerClosed, other->isUpperClosed());
                else
                    return std::make_shared<BasicInterval<Type>>(other->getLowerBound(), upperBound, other->isLowerClosed(), this->upperClosed);
                    
            }
        } else {
            return std::make_shared<BasicInterval<Type>>();
        }
    }

    bool isDiscrete() const override {
        return upperBound == lowerBound;
    }

    bool isContinuous() const override {
        return !isDiscrete();
    }

    bool isFinite() const override {
        return !isInfinite();
    }

    bool isInfinite() const override {
        return (lowerInfinite || upperInfinite);
    }

    bool isEmpty() const override {
        return lowerBound == upperBound && !lowerClosed && !upperClosed;
    }

    // No need to override addSubInterval, flatten, isLeaf, and getSubIntervals
    // as the default implementations in the interface are sufficient

private:
    void setLowerBound(Type lowerBound) {
        this->lowerBound = lowerBound;
        setLowerInfinite(false);
    }

    void setUpperBound(Type upperBound) {
        this->upperBound = upperBound;
        setUpperInfinite(false);
    }

    void setLowerClosed(bool lowerClosed) {
        this->lowerClosed = lowerClosed;
    }

    void setUpperClosed(bool upperClosed) {
        this->upperClosed = upperClosed;
    }

    void setLowerInfinite(bool lowerInfinite) {
        this->lowerInfinite = lowerInfinite;
    }

    void setUpperInfinite(bool upperInfinite) {
        this->upperInfinite = upperInfinite;
    }
};

} // namespace ArithmeticPoints