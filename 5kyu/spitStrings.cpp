#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <catch2/catch.hpp>

using namespace std;

void do_test(const string& input, const vector<string>& expected)
{
    REQUIRE(solution(input) == expected);
}

std::vector<std::string> solution(const std::string &s)
{
    string new_s = s;
    vector<string> pars_words;
    if(new_s.length() % 2  != 0)
    {
        new_s += '_';
    }
    for(int i = 0; i < new_s.size(); i += 2)
    {
        string word = new_s.substr(i, 2);
        if(word.length() == 2)
        {
            pars_words.push_back(word);
        }
    }
   

    return pars_words; 
}

Describe(sample_test)
{
    It(even_length)
    {
       do_test("abcdef", {"ab", "cd", "ef"});
       do_test("HelloWorld", {"He", "ll", "oW", "or", "ld"});
    }
    It(odd_length)
    {
       do_test("abcde", {"ab", "cd", "e_"});
       do_test("LovePizza", {"Lo", "ve", "Pi", "zz", "a_"});
    }
};
