#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    if (snail_map.empty() || snail_map[0].empty()) return {};
    else if(snail_map.size() == 1) return snail_map[0];
    vector<int> new_map;
    int top = 0;
    int bottom = snail_map.size() - 1;
    int left = 0;
    int right = snail_map[0].size() - 1;
   while (top <= bottom && left <= right) 
    {
        
        for (int i = left; i <= right; ++i) {
            new_map.push_back(snail_map[top][i]);
        }
        top++; 

        
        for (int i = top; i <= bottom; ++i) {
            new_map.push_back(snail_map[i][right]);
        }
        right--; 

        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                new_map.push_back(snail_map[bottom][i]);
            }
            bottom--;
        }   

        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                new_map.push_back(snail_map[i][left]);
            }
            left++; 
        }
    }
    return new_map;
}

    

  


int main()
{
    vector<vector<int>> v = {{1,2,3}, {8,9,4}, {7,6,5}};
    vector<int> new_v = snail(v);
    for(int i = 0; i < new_v.size(); i++)
    {
        cout<<new_v[i]<<", ";
    }
}