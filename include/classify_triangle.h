#if !defined(TRIANGLE_CLASSIFIER_H)
#define TRIANGLE_CLASSIFIER_H

#include <stdexcept>

namespace classify_triangle {
/**
 * @brief Representation for the type of triangle.
 *
 * Equilateral triangles have all three sides the same length. Isosceles
 * triangles have two sides the same. Scalene have none.
 * */
enum TriangleType { ISOSCELES, EQUILATERAL, SCALENE };

/**
 * @brief Determine the type of a triangle based on the length of its sides.
 * @param side1 The length of the first side of the triangle.
 * @param side2 The length of the second side of the triangle.
 * @param side3 The length of the third side of the triangle.
 * @return TriangleType The type of triangle with the given side lengths.
 * */
TriangleType classifyTriangle(double side1, double side2, double side3);
}  // namespace classify_triangle

#endif  // TRIANGLE_CLASSIFIER_H
