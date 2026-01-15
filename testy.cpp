#define BOOST_TEST_MODULE Hello 
#include <boost/test/included/unit_test.hpp> 

int dodaj( int i, int j )
{
    return i + j;
}

int odejmij(int i, int j)
{
    return i - j;
}

double przyspieszenie( int m, int a)
{
    return m * a;
}

BOOST_AUTO_TEST_SUITE(Matematyka)
BOOST_AUTO_TEST_CASE( testDodaj )
{
    BOOST_REQUIRE( dodaj( 2, 2 ) == 8 );
}
BOOST_AUTO_TEST_CASE(testOdejmij)
{
    BOOST_CHECK(odejmij(4, 2) == 6);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Fizyka)
BOOST_AUTO_TEST_CASE(testPrzyspieszenie)
{
    BOOST_WARN(przyspieszenie(25, 10) == 200);
}
BOOST_AUTO_TEST_SUITE_END()