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
} RomanNumerals;