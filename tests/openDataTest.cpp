#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "MatrixSolver.hpp"
#include "matrixIO.hpp"

using namespace std;
using namespace Eigen;
using namespace matrixIO;

struct openDataFixture {
  openDataFixture()
  {
    A = MatrixXd(3, 3);
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
  }

  MatrixXd A;
};

BOOST_FIXTURE_TEST_SUITE(openDataTests, openDataFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openDataTest)
{
  Configuration configuration{"openDataTestConfig.yml"};

  const MatrixXd B = openData(configuration.matrixFileName,
                                        configuration.matrixSize);
  for (int i=0; i<configuration.matrixSize; i++)
    for (int j=0; j<configuration.matrixSize; j++)
      BOOST_TEST(B(i,j) == A(i,j));
}

BOOST_AUTO_TEST_SUITE_END()