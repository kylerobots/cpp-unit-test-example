#include <iostream>

#include "classify_triangle.h"

int main(int, char**) {
  classify_triangle::TriangleType type =
      classify_triangle::classifyTriangle(1.0, 1.0, 1.0);
  switch (type) {
    case classify_triangle::TriangleType::EQUILATERAL:
      std::cout << "This is an equilateral triangle." << std::endl;
      break;
    case classify_triangle::TriangleType::ISOSCELES:
      std::cout << "This is an isosceles triangle." << std::endl;
      break;
    case classify_triangle::TriangleType::SCALENE:
      std::cout << "This is a scalene triangle." << std::endl;
      break;
    default:
      std::cout << "There was an error." << std::endl;
      break;
  }
}
