// test1.h:

#include <cxxtest/TestSuite.h>
#include "../matrix.h"
#include "../common.h"

using namespace std;

int debug=1;

class Test1 : public CxxTest::TestSuite
{
public:
  void testAddition( void )
  {
      TS_ASSERT( 1 + 1 > 1 );
      TS_ASSERT_EQUALS( 1 + 1, 2 );
  }

  void test_01_matrix_transpose(void) {}

  // transpose of matrix test
  void test_02_matrix_parse_from_string(void)
  {
      Matrix::Matrix<int> m1 = "[1,2;3,4]";
      TS_ASSERT_EQUALS( m1.dim, 2 );
      TS_ASSERT_EQUALS( m1(1,2), 2 );
  }
};
