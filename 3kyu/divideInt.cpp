#define BOOST_TEST_MODULE divide
#include <boost/test/included/unit_test.hpp> 
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

bool isGreaterOrEqual(const string& a, const string& b) {
    if (a.length() != b.length()) return a.length() > b.length();
    return a >= b;
}

string subtract_strings(string a, string b) {
    string res = "";
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    while (i >= 0) {
        int val1 = a[i--] - '0';
        int val2 = (j >= 0) ? (b[j--] - '0') : 0;
        int diff = val1 - val2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res += to_string(diff);
    }
    while (res.length() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
  
pair<string, string> divide_strings(string a, string b) {

    if (a == "0") return {"0", "0"};
    if (!isGreaterOrEqual(a, b)) return {"0", a};

    string quotient = "";
    string current_remainder = "";

    for (char c : a) {
        current_remainder += c;
        size_t first = current_remainder.find_first_not_of('0');
        if (first == string::npos) current_remainder = "0";
        else current_remainder = current_remainder.substr(first);

        int count = 0;
        while (isGreaterOrEqual(current_remainder, b)) {
            current_remainder = subtract_strings(current_remainder, b);
            count++;
        }
        quotient += to_string(count);
    }

    size_t q_first = quotient.find_first_not_of('0');
    if (q_first == string::npos) quotient = "0";
    else quotient = quotient.substr(q_first);

    return {quotient, current_remainder};
}




BOOST_AUTO_TEST_SUITE(DivideIntAdvanced)
BOOST_AUTO_TEST_CASE(ComparisonTests)
{
    BOOST_CHECK_MESSAGE(isGreaterOrEqual("100", "50"), "100 powinno być większe od 50");
    BOOST_CHECK_MESSAGE(isGreaterOrEqual("50", "100") == false, "50 nie powinno być większe od 100");
    BOOST_CHECK_MESSAGE(isGreaterOrEqual("100", "100"), "Liczby równe powinny zwracać true");
    BOOST_CHECK_MESSAGE(isGreaterOrEqual("1000", "999"), "Dłuższy string powinien być większy");
}

BOOST_AUTO_TEST_CASE(SubtractionTests)
{
    BOOST_CHECK_EQUAL(subtract_strings("10", "1"), "9");
    BOOST_CHECK_EQUAL(subtract_strings("100", "100"), "0");
    BOOST_CHECK_EQUAL(subtract_strings("1000", "1"), "999");
}

BOOST_AUTO_TEST_CASE(MainDivisionTests)
{
    
    auto res1 = divide_strings("100", "10");
    BOOST_CHECK_EQUAL(res1.first, "10");
    BOOST_CHECK_EQUAL(res1.second, "0");

    
    auto res2 = divide_strings("10", "3");
    BOOST_CHECK_EQUAL(res2.first, "3");
    BOOST_CHECK_EQUAL(res2.second, "1");

    auto res3 = divide_strings("5", "10");
    BOOST_CHECK_EQUAL(res3.first, "0");
    BOOST_CHECK_EQUAL(res3.second, "5");
}

BOOST_AUTO_TEST_CASE(EdgeCaseTests)
{
    auto resZero = divide_strings("0", "500");
    BOOST_CHECK_EQUAL(resZero.first, "0");
    BOOST_CHECK_EQUAL(resZero.second, "0");

    string bigA = "1000000000000000000000000000000"; 
    string bigB = "100000000000000000000000000000";  
    auto resBig = divide_strings(bigA, bigB);
    BOOST_CHECK_EQUAL(resBig.first, "10");
    BOOST_CHECK_EQUAL(resBig.second, "0");
}

BOOST_AUTO_TEST_SUITE_END()