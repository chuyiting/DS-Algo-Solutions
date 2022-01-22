//
//  647-palindromic-substrings.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/20.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int l = s.size(), sol = 0;
        int dp[l][l];
        
        // base case
        for (int i = 0; i < l; i++) {
            dp[i][i] = 1;
            sol++;
        }
        
        for (int d = 1; d < l; d++) {
            for (int i = 0; (i + d) < l; i++) {
                int j= i + d;
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (d == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
                sol = dp[i][j] ? sol+1 : sol;
                
            }
        }
        
        return sol;
    }
};
