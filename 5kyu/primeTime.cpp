#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool primeer(unsigned n)
{
    for(unsigned i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

std::vector<unsigned> prime(unsigned n){
    vector<unsigned> liczby_pierwsze;
    for(int i = 0; i < 3; i++)
    {
        if(n == i)
        {
            cout<<"Invalid answer for "<<i;
        }
    }
    for(unsigned i = 2; i <= n; i++)
    {
        if(primeer(i) == true)
        {
            liczby_pierwsze.push_back(i);
        }
    }
    return liczby_pierwsze;
}

int main()
{
    unsigned n = 0;
    vector<unsigned> wektorek = prime(n);
    for(int i = 0; i < wektorek.size(); i++)
    {
        cout<<wektorek[i]<<", ";
    }

}