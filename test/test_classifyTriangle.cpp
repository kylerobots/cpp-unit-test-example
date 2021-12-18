#include <gtest/gtest.h>

#include "classify_triangle.h"

/// @test Test that equilateral triangles are correctly identified.
TEST(classifyTriangle, test_equilateral) {
  classify_triangle::TriangleType result =
      classify_triangle::classifyTriangle(1.0, 1.0, 1.0);
  ASSERT_EQ(result, classify_triangle::TriangleType::EQUILATERAL);
}

/// @test Test that isosceles triangles don't care about the order.
TEST(classifyTriangle, test_isosceles_order) {
  classify_triangle::TriangleType result =
      classify_triangle::classifyTriangle(1.0, 1.0, 1.5);
  ASSERT_EQ(result, classify_triangle::TriangleType::ISOSCELES);
  result = classify_triangle::classifyTriangle(1.0, 1.5, 1.0);
  ASSERT_EQ(result, classify_triangle::TriangleType::ISOSCELES);
  result = classify_triangle::classifyTriangle(1.5, 1.0, 1.0);
  ASSERT_EQ(result, classify_triangle::TriangleType::ISOSCELES);
}

/// @test Test that scalene triangles are properly identified.
TEST(classifyTriangle, test_scalene) {
  classify_triangle::TriangleType result =
      classify_triangle::classifyTriangle(3.0, 4.0, 5.0);
  ASSERT_EQ(result, classify_triangle::TriangleType::SCALENE);
}

/// @test Test that negatives and zeroes are rejected.
TEST(classifyTriangle, test_nonpositive_numbers) {
  ASSERT_THROW(classify_triangle::classifyTriangle(0.0, 1.0, 2.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(1.0, 0.0, 2.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(2.0, 1.0, 0.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(-1.0, 1.0, 1.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(1.0, -1.0, 1.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(1.0, 1.0, -1.0),
               std::invalid_argument);
}

/// @test Test that the triangle inequality property holds.
TEST(classifyTriangle, test_triangle_inequality) {
  ASSERT_THROW(classify_triangle::classifyTriangle(1.0, 1.0, 2.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(1.0, 2.0, 1.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(2.0, 1.0, 1.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(1.0, 0.9, 2.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(0.9, 2.0, 1.0),
               std::invalid_argument);
  ASSERT_THROW(classify_triangle::classifyTriangle(2.0, 1.0, 0.9),
               std::invalid_argument);
}