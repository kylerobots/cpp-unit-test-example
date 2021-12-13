#include "classify_triangle.h"

namespace classify_triangle {
TriangleType classifyTriangle(double side1, double side2, double side3) {
  if (side1 == side2 && side2 == side3) {
    return TriangleType::EQUILATERAL;
  } else if (side1 == side2 && side2 != side3) {
    return TriangleType::ISOSCELES;
  } else {
    return TriangleType::SCALENE;
  }
}
}  // namespace classify_triangle
