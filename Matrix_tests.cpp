// Project UID af1f95f547e44c8ea88730dfb185559d
 
#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
 
using namespace std;
 
// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 3;
  const int height = 5;
  const int value = 42;
 
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  for (int r = 0; r < height; ++r)
  {
    for (int c = 0; c < width; ++c)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }
  delete mat;
}

TEST(test_print)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 3;
  const int height = 3;
  const int value = 50;
 
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  
  ostringstream os;
  ostringstream test;
  Matrix_print(mat, test);
  os << "3 3\n";
  os << "50 50 50 \n";
  os << "50 50 50 \n";
  os << "50 50 50 \n";
  ASSERT_EQUAL(os.str(), test.str());
  delete mat;
}


TEST(test_max)
{
  Matrix *mat = new Matrix;
 
  const int width = 6;
  const int height = 6;
  const int value = 25;
  int maxValue = 50;
 
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = maxValue;
 
  ASSERT_EQUAL(Matrix_max(mat), maxValue);
 
  delete mat;
}
 
TEST(test_fill_border)
{
  Matrix *mat = new Matrix;
 
  const int width = 6;
  const int height = 6;
  int value = 25;
 
  Matrix_init(mat, width, height);
 
  Matrix_fill_border(mat, value);

    for (int i = 0; i < height; i++)
  {
    ASSERT_EQUAL(*Matrix_at(mat, 0, i), value);
    ASSERT_EQUAL(*Matrix_at(mat, Matrix_height(mat) - 1, i) ,value);
  }
 
  for (int i = 0; i < width; i++)
  {
    ASSERT_EQUAL(*Matrix_at(mat, i, 0), value);
    ASSERT_EQUAL(*Matrix_at(mat, i, Matrix_width(mat) - 1), value);
  }

 
  delete mat; // delete the Matrix
}
 
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(test_width)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 6;
  const int height = 6;
  Matrix_init(mat, width, height);
 
  ASSERT_EQUAL(Matrix_width(mat), width);
 
  delete mat;
}
 
TEST(test_height)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 6;
  const int height = 6;
  Matrix_init(mat, width, height);
 
  ASSERT_EQUAL(Matrix_height(mat), width);
 
  delete mat;
}
 
TEST(test_row)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 6;
  const int height = 6;
  const int value = 50;
  int row = 3;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  int *pointer = &(*Matrix_at(mat, row, 4));
 
  ASSERT_EQUAL(Matrix_row(mat, pointer), row);
  delete mat;
}

TEST(test_row_large)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 10;
  const int height = 10;
  const int value = 50;
  int row = 5;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  int *pointer = &(*Matrix_at(mat, row, 5));
 
  ASSERT_EQUAL(Matrix_row(mat, pointer), row);
  delete mat;
}
 
TEST(test_column)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 6;
  const int height = 6;
  const int value = 50;
  int column = 5;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  int *pointer = &(*Matrix_at(mat, 5, column));
 
  ASSERT_EQUAL(Matrix_column(mat, pointer), column);
  delete mat;
}

TEST(test_column_large)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 10;
  const int height = 10;
  const int value = 50;
  int column = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  int *pointer = &(*Matrix_at(mat, 5, column));
 
  ASSERT_EQUAL(Matrix_column(mat, pointer), column);
  delete mat;
}

TEST(test_matrix_column_of_min_value_in_row)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 6;
  const int height = 6;
  const int value = 50;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = 10;
 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, width - 1), 0);
  delete mat;
}

TEST(test_matrix_column_of_min_value_in_row_edge)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 10;
  const int height = 10;
  const int value = 50;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 9) = 5;

 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, width - 1), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, width), 9);
  delete mat;
}

TEST(test_matrix_column_of_min_value_in_row_multiple)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 10;
  const int height = 10;
  const int value = 50;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 9) = 10;

 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, width), 0);
  delete mat;
}

TEST(test_matrix_column_of_min_value_in_row_edges)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 10;
  const int height = 10;
  const int value = 50;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = 10;
  *Matrix_at(mat, 0, 9) = 9;

 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, width-1), 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, width), 9);
  delete mat;
}

TEST(test_matrix_min_value_in_row)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 6;
  const int height = 6;
  const int value = 50;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = 10;

  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, width - 1), 10);
  delete mat;
}
TEST (test_min_value_in_row_edge) {

  const int width = 10;
  const int height = 10;
  const int value = 50;
  Matrix *mat = new Matrix;

  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  *Matrix_at(mat, 0, 6) = 45;
  *Matrix_at(mat, 0, 8) = 2;
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,6,8), 45);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,6,9), 2);
  delete mat;
}
 TEST(test_matrix_min_value_in_row_large)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
 
  const int width = 50;
  const int height = 50;
  const int value = 50;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  *Matrix_at(mat, 0, 0) = 10;

  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, width - 1), 10);
  delete mat;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here