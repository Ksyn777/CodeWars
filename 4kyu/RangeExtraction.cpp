#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string range_extraction(std::vector<int> args) {
    sort(args.begin(), args.end());
    string new_args;
    for (size_t i = 0; i < args.size(); i++)
    {
        int count = i;
        while(count + 1 < args.size() && args[count + 1] == args[count] + 1)
        {
            count++;
        }
        if(count - i >= 2)
        {
            int liczba_one = args[i];
            int liczba_two = args[count];
            string s = to_string(liczba_one);
            string ss = to_string(liczba_two);
            new_args += s + "-" + ss;
            i = count;

        }
        else
        {
            int liczba_a = args[i];
            string g = to_string(liczba_a);
            new_args += g;
        }
        if (i < args.size() - 1) 
        {
            new_args += ",";
        }
        
        
    }
    
    return new_args;
};

int main()
{
    vector<int> v = {-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
    string ss = range_extraction(v);
    cout<<ss<<" ";
}