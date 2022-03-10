#include "classify_triangle.h"

namespace classify_triangle {
TriangleType classifyTriangle(double side1, double side2, double side3) {
  // First, check that all numbers are positive.
  if (side1 <= 0.0 || side2 <= 0.0 || side3 <= 0.0) {
    throw std::invalid_argument("Triangle sides must all be positive.");
  }
  // Then, verify the triangle inequality holds.
  if (side1 >= side2 + side3 || side2 >= side1 + side3 ||
      side3 >= side1 + side2) {
    throw std::invalid_argument("The triangle inequality must hold.");
  }
  // If the above hold, then just figure out what type of triangle it is.
  if (side1 == side2 && side2 == side3) {
    return TriangleType::EQUILATERAL;
  } else if (side1 == side2 || side2 == side3 || side1 == side3) {
    return TriangleType::ISOSCELES;
  } else {
    return TriangleType::SCALENE;
  }
}
}  // namespace classify_triangle
