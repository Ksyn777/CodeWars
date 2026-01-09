#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string sum_strings(const string& a, const string& b) {
    string result = "";
    int i = a.length() - 1; 
    int j = b.length() - 1; 
    int carry = 0;          

    
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0'; 
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        carry = sum / 10;      
        result += to_string(sum % 10); 
    }

    
    reverse(result.begin(), result.end());
    
    return result;
}

int main()
{
    string example = sum_strings("123", "456");
    cout<<example;
}