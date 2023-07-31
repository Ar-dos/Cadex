#ifndef CURVE
#define CURVE

#include "point3d.h"

template <class T>
class Curve {
 public:
  Curve(T x, T y, T z) : position_(x, y, z) {}

  virtual ~Curve() = default;

  virtual Point3d<T> GetPoint(double angle) const = 0;

  virtual Point3d<T> GetDerivative(double angle) const = 0;

  Point3d<T> GetPosition() const { return position_; }

 private:
  Point3d<T> position_;
};

#endif /* CURVE */