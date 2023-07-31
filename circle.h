#ifndef CIRCLE
#define CIRCLE

#include "ellipse.h"

template <class T>
class Circle : public Curve<T> {
 public:
  Circle(T x, T y, T z, T radius) : Curve<T>(x, y, z), radius_(radius) {}

  Circle(T x, T y, T radius) : Circle(x, y, 0, radius) {}

  Point3d<T> GetPoint(double t) const override {
    return Point3d<T>(
        static_cast<T>(this->GetPosition().GetX() + radius_ * cos(t)),
        static_cast<T>(this->GetPosition().GetY() + radius_ * sin(t)),
        this->GetPosition().GetZ());
  }

  Point3d<T> GetDerivative(double t) const override {
    return Point3d<T>(static_cast<T>(radius_ * -sin(t)),
                      static_cast<T>(radius_ * cos(t)), 0);
  }

  T GetRadius() { return radius_; }

 private:
  T radius_;
};

#endif /* CIRCLE */