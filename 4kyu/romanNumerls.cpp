#define BOOST_TEST_MODULE romanNumbers
#include <boost/test/included/unit_test.hpp> 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<string, int>> romanian = {{"M", 1000}, {"CM", 900}, 
                                       {"D", 500}, {"CD", 400}, 
                                        {"C", 100}, {"XC", 90},
                                        {"L", 50}, {"XL", 40},
                                        {"X", 10}, {"IX", 9},
                                        {"V", 5}, {"IV", 4},
                                        {"I", 1} };

class RomanHelper{
  public:
    std::string to_roman(unsigned int n){
      string result;
      for(auto const&[klucz, wartosc] : romanian)
      {
        while(n >= wartosc)
        {
            n -= wartosc;
            result += klucz;
        }

      } 
      return result;;
    }
  int from_roman(std::string rn) {
    int result_2 = 0;
    for (size_t i = 0; i < rn.length(); i++) {
        if (i + 1 < rn.length()) {
            string dwa_znaki = {rn[i], rn[i+1]};
            bool znaleziono_pare = false;
            
            for (auto const& [klucz, wartosc] : romanian) {
                if (klucz == dwa_znaki) {
                    result_2 += wartosc;
                    i++; 
                    znaleziono_pare = true;
                    break;
                }
            }
            if (znaleziono_pare) continue;
        }
        string jeden_znak(1, rn[i]);
        for (auto const& [klucz, wartosc] : romanian) {
            if (klucz == jeden_znak) {
                result_2 += wartosc;
                break;
            }
        }
    }
    return result_2;
  }
};


BOOST_AUTO_TEST_SUITE(Romanian_Numbers)
BOOST_AUTO_TEST_CASE(toRomanTest)
{
    RomanHelper roman;
    BOOST_CHECK_EQUAL(roman.to_roman(1), "I");
    BOOST_CHECK_EQUAL(roman.to_roman(2000), "MM");
    BOOST_CHECK_EQUAL(roman.to_roman(1666), "MDCLXVI"); 
    BOOST_CHECK_EQUAL(roman.to_roman(1994), "MCMXCIV");
    BOOST_CHECK_EQUAL(roman.to_roman(444), "CDXLIV");
}
BOOST_AUTO_TEST_CASE(fromRomanTest)
{
    RomanHelper roman;
    BOOST_CHECK_EQUAL(roman.from_roman("I"), 1);
    BOOST_CHECK_EQUAL(roman.from_roman("MM"), 2000);
    BOOST_CHECK_EQUAL(roman.from_roman("MDCLXVI"), 1666);
    BOOST_CHECK_EQUAL(roman.from_roman("MCMXCIV"), 1994);
    BOOST_CHECK_EQUAL(roman.from_roman("CDXLIV"), 444);

}
BOOST_AUTO_TEST_SUITE_END()