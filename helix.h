#ifndef HELIX
#define HELIX

#include <cmath>

#include "Curve.h"

template <class T>
class Helix : public Curve<T> {
 public:
  Helix(T x, T y, T radius, T step) : Helix<T>(x, y, 0, radius, step) {}

  Helix(T x, T y, T z, T radius, T step)
      : Curve<T>(x, y, z), radius_(radius), step_(step) {}

  Point3d<T> GetPoint(double t) const override {
    return Point3d<T>(
        static_cast<T>(this->GetPosition().GetX() + radius_ * cos(t) * t),
        static_cast<T>(this->GetPosition().GetY() + radius_ * sin(t) * t),
        this->GetPosition().GetZ() + t * step_);
  }

  Point3d<T> GetDerivative(double t) const override {
    return Point3d<T>(static_cast<T>(radius_ * (cos(t) - t * sin(t))),
                      static_cast<T>(radius_ * (sin(t) + t * cos(t))), step_);
  }

 private:
  T radius_;
  T step_;
};

#endif /* HELIX */