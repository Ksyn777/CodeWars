#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;


int64_t solve(const std::string &s, const std::string &ops)
{
    vector<vector<int64_t>> True_results;
    vector<vector<int64_t>> False_results;
    int n = s.size();
    True_results.resize(n, vector<int64_t>(n, 0));
    False_results.resize(n, vector<int64_t>(n, 0));
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 't')
        {
            True_results[i][i] = 1;
            False_results[i][i] = 0;
        }
        else
        {
            True_results[i][i] = 0;
            False_results[i][i] = 1;
        }
    }

    for(int len = 1; len < n; len++)
    {
        for(int i = 0; i < n - len; i++)
        {
            int j = i + len;
            for(int k = i; k < j; k++)
            {
                char op = ops[k];
                int64_t leftTrue = True_results[i][k];
                int64_t leftFalse = False_results[i][k];
                int64_t rightTrue = True_results[k + 1][j];
                int64_t rightFalse = False_results[k + 1][j];

                if(op == '&')
                {
                    True_results[i][j] += leftTrue * rightTrue;
                    False_results[i][j] += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
                }
                else if(op == '|')
                {
                    True_results[i][j] += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                    False_results[i][j] += leftFalse * rightFalse;
                }
                else if(op == '^')
                {
                    True_results[i][j] += leftTrue * rightFalse + leftFalse * rightTrue;
                    False_results[i][j] += leftTrue * rightTrue + leftFalse * rightFalse;
                }
            }
        }
    }

    return True_results[0][n - 1];
}