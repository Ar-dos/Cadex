#ifndef ELLIPSE
#define ELLIPSE

#include <cmath>

#include "Curve.h"

template <class T>
class Ellipse : public Curve<T> {
 public:
  Ellipse(T x, T y, T z, T a, T b) : Curve<T>(x, y, z), a_(a), b_(b) {}

  Ellipse(T x, T y, T a, T b) : Ellipse(x, y, static_cast<T>(0), a, b) {}

  Point3d<T> GetPoint(double t) const override {
    return Point3d<T>(static_cast<T>(this->GetPosition().GetX() + a_ * cos(t)),
                      static_cast<T>(this->GetPosition().GetY() + b_ * sin(t)),
                      this->GetPosition().GetZ());
  }

  Point3d<T> GetDerivative(double t) const override {
    return Point3d<T>(static_cast<T>(a_ * -sin(t)), static_cast<T>(b_ * cos(t)),
                      0);
  }

 private:
  T a_;
  T b_;
};

#endif /* ELLIPSE */