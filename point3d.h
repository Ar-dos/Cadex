#ifndef POINT3D
#define POINT3D

#include <sstream>

template <class T>

class Point3d {
 public:
  Point3d(T x, T y, T z) : x_(x), y_(y), z_(z) {}

  std::string str() const {
    std::ostringstream ss;
    ss << std::fixed;
    ss << "{" << x_ << "," << y_ << "," << z_ << "}";
    return ss.str();
  }

  T GetX() const { return x_; }
  T GetY() const { return y_; }
  T GetZ() const { return z_; }

 private:
  T x_;
  T y_;
  T z_;
};

#endif /* POINT3D */