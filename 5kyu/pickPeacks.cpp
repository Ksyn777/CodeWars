#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#include <vector>

struct PeakData {
  std::vector<int> pos;   
  std::vector<int> peaks; 
};

PeakData pick_peaks(const std::vector<int> &v) {
    PeakData result;
    if (v.empty()) return result;

    int candidate_pos = -1;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > v[i - 1]) {
            candidate_pos = i;
        } 
        else if (v[i] < v[i - 1]) {
            if (candidate_pos != -1) {
                result.pos.push_back(candidate_pos);
                result.peaks.push_back(v[candidate_pos]);
                
                candidate_pos = -1;
            }
        }
        
    }

    return result;
}