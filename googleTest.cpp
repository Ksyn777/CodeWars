#include <string>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <memory>

using namespace std;


bool czyPalindrom(std::string s) {
    if (s.empty()) return true;
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

class Osoba
{
    private:
        string imie;
        int wiek;
    public:
        Osoba(string i, int w) : imie(i), wiek(w) {}
        void urodziny() { wiek++; }
        string getInfo() const {
            return imie + " " + to_string(wiek);
        }
        int getWiek() const { return wiek; }

};

int dodawanie(int a, int b)
{
    return a + b;
}

int resztaDzielenie(int a, int b)
{
    return a % b;
}

TEST(DzialaniaTest, Dodaj)
{
    EXPECT_EQ(10, dodawanie(5, 5)) <<"Bledny wynik!";
    EXPECT_EQ(0, dodawanie(1, -1)) <<"Bledny wynik!";

}

TEST(DzialaniaTest, DzielenieBEzReszty)
{
    EXPECT_EQ(1, resztaDzielenie(3, 2));
    ASSERT_EQ(0, resztaDzielenie(100, 10));
}

class OsobaTest : public ::testing::Test {

    public:
        unique_ptr<Osoba> jan;
        unique_ptr<Osoba> anna;
        

    void SetUp() override 
    {
        jan = make_unique<Osoba>("Jan", 20);
        anna = make_unique<Osoba>("Anna", 17);
    }

    //void TearDown() override{
    
};

TEST_F(OsobaTest, SprawdzDanePoczatkowe)
{
    EXPECT_EQ(jan->getWiek(), 20);
    EXPECT_EQ(jan->getInfo(), "Jan 20");
    EXPECT_EQ(anna->getWiek(), 17);
    EXPECT_EQ(anna->getInfo(), "Anna 17");
    
}

TEST_F(OsobaTest, TestUrodzin)
{
    jan->urodziny();
    EXPECT_EQ(jan->getWiek(), 21);
    EXPECT_EQ(jan->getInfo(), "Jan 21");
    anna->urodziny();
    EXPECT_EQ(anna->getWiek(), 18);
    EXPECT_EQ(anna->getInfo(), "Anna 18");
}

TEST_F(OsobaTest, Porownanie)
{
    EXPECT_GT(jan->getWiek(), anna->getWiek());
}

//Klasa bazowa dla parametrów
class ResztaDzielenieTest : public testing::TestWithParam<tuple<int, int, int>> {};

//Test korzystający z parametrów
TEST_P(ResztaDzielenieTest, SprawdzWynik)
{
    auto[a, b, expected] = GetParam();
    EXPECT_EQ(resztaDzielenie(a, b), expected);
}

INSTANTIATE_TEST_SUITE_P(

    SeriaTestow,
    ResztaDzielenieTest,
    testing::Values(
        make_tuple(4, 2, 0),
        make_tuple(10, 3, 1)
    )
);


class Palindromtest : public ::testing::TestWithParam<tuple<string, bool>> {};

TEST_P(Palindromtest, SprawdzRozneSlowa)
{
    auto [slowo, wynik] = GetParam();
    EXPECT_EQ(czyPalindrom(slowo), wynik)
    << "Blad dla slowa: " << slowo;
}

INSTANTIATE_TEST_SUITE_P(
    ZestawSlow,
    Palindromtest,
    testing::Values(
        make_tuple("kajak", true),
        make_tuple("radar", true),
        make_tuple("potop", true),
        make_tuple("level", true),
        make_tuple("kot", false),
        make_tuple("programowanie", false),
        make_tuple("", true) //
    )
);

int dzielenie(int a, int b) {
    if (b == 0) throw invalid_argument("Dzielenie przez zero!");
    return a / b;
}

TEST(DzielenieBledy, RzucaWyjatek) {
    EXPECT_THROW(dzielenie(10, 0), invalid_argument);
    EXPECT_NO_THROW(dzielenie(10, 2));
}