//
//  424-longest-repeating-character-replacement.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/6.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

// Sliding window
// !!!!!!!!!! Practice for a few more times please
// Cool technique: Never decrease maxf cuz the goal is to find the max window size; window size - maxf <= k; therefore, if maxf decreases, it is not optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = (int) s.size();
        int windowStart = 0;
        int sol = 0;
        unordered_map<char, int> count;
        int maxf = 0;
        
        for (int i = 0; i < n; i++) {
            int windowSize = i - windowStart + 1;
            
            char c = s.at(i);
            if (count.find(c) == count.end()) {
                count[c] = 1;
            } else {
                count[c]++;
            }
            
            if (count[c] > maxf) maxf = count[c];
            
            if (windowSize - maxf <= k) {
                sol = max(sol, windowSize);
            } else {
                count[s.at(windowStart)]--;
                windowStart++;
            }
        }
        return sol;
    }
};
