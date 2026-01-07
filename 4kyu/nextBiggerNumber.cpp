#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long nextBigger(long n) {
    string liczba = to_string(n);
    int len = liczba.length();
    int index = -1;
    
    for(int i = len - 1; i > 0; i--) {
        if(liczba[i] > liczba[i - 1]) {
            index = i - 1;
            break;
        }
    }

    if(index == -1) return -1;

    string first = liczba.substr(0, index);
    
    string last = liczba.substr(index + 1);
    
    char pivot = liczba[index];
    int swap_idx = -1;
    sort(last.begin(), last.end()); 

    for(int i = 0; i < last.length(); i++) {
        if(last[i] > pivot) {
            swap_idx = i;
            break;
        }
    }

    char temp = pivot;
    pivot = last[swap_idx];
    last[swap_idx] = temp;
    
    sort(last.begin(), last.end());

    string end = first + pivot + last;
    
    return stol(end);
}

long nextBigger_two(long n) {
    string s = to_string(n);
    if (next_permutation(s.begin(), s.end())) {
        return stoul(s);
    }
    return -1;
}