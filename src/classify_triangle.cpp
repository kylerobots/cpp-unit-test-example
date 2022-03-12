#include "classify_triangle.h"

namespace classify_triangle {
auto classifyTriangle(double side1, double side2, double side3)
    -> TriangleType {
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
  TriangleType result = TriangleType::SCALENE;
  if (side1 == side2 && side2 == side3) {
    result = TriangleType::EQUILATERAL;
  } else if (side1 == side2 || side2 == side3 || side1 == side3) {
    result = TriangleType::ISOSCELES;
  } else {
    result = TriangleType::SCALENE;
  }
  return result;
}
}  // namespace classify_triangle
