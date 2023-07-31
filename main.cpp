#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "circle.h"
#include "curve.h"
#include "ellipse.h"
#include "helix.h"

int main() {
  std::vector<std::shared_ptr<Curve<int>>> first;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<int> rand_value(1, 100);
  std::uniform_int_distribution<int> rand_type(1, 3);

  size_t vector_size = 100;

  // Populate a container (e.g. vector or list) of objects of these types
  // created in random manner with random parameters

  for (size_t i = 0; i < vector_size; i++) {
    int type = rand_type(eng);
    if (type == 1)
      first.push_back(std::make_shared<Circle<int>>(
          rand_value(eng), rand_value(eng), rand_value(eng)));
    else if (type == 2)
      first.push_back(std::make_shared<Ellipse<int>>(
          rand_value(eng), rand_value(eng), rand_value(eng), rand_value(eng)));
    else if (type == 3)
      first.push_back(std::make_shared<Helix<int>>(
          rand_value(eng), rand_value(eng), rand_value(eng), rand_value(eng),
          rand_value(eng)));
  }

  // Print coordinates of points and derivatives of all curves in the container
  // at t=PI/4.

  for (size_t i = 0; i < vector_size; i++) {
    std::cout << "Point: " << first[i].get()->GetPoint(M_PI / 4).str()
              << " Derivative: "
              << first[i].get()->GetDerivative(M_PI / 4).str() << std::endl;
  }

  // Populate a second container that would contain only circles from the first
  // container. Make sure the second container shares (i.e. not clones) circles
  // of the first one, e.g. via pointers.

  std::vector<std::shared_ptr<Circle<int>>> second;

  for (size_t i = 0; i < vector_size; i++) {
    if (std::dynamic_pointer_cast<Circle<int>>(first[i]))
      second.push_back(std::dynamic_pointer_cast<Circle<int>>(first[i]));
  }

  // Sort the second container in the ascending order of circles’ radii. That
  // is, the first element has the smallest radius, the last - the greatest.

  for (size_t i = 0; i < second.size(); i++)
    std::cout << second[i].get()->GetPosition().str()
              << " Radius: " << second[i].get()->GetRadius() << std::endl;
  std::cout << std::endl;

  std::sort(
      second.begin(), second.end(),
      [](std::shared_ptr<Circle<int>> &lhs, std::shared_ptr<Circle<int>> &rhs) {
        return lhs->GetRadius() < rhs->GetRadius();
      });

  for (size_t i = 0; i < second.size(); i++)
    std::cout << second[i].get()->GetPosition().str()
              << " Radius: " << second[i].get()->GetRadius() << std::endl;

  // Compute the total sum of radii of all curves in the second container.

  int sum_radius = 0;
  for (size_t i = 0; i < second.size(); i++) {
    sum_radius += second[i].get()->GetRadius();
  }
  std::cout << sum_radius << std::endl;

  return 0;
}