//
//  3-longest-substring-without-repeating-characters.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/8.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0;
        int sol = 0;
        unordered_map<char, bool> existence;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s.at(i);
            if (existence.find(c) == existence.end() || !existence[c]) {
                existence[c] = true;
            } else {
                while (existence[c]) {
                    existence[s.at(windowStart)] = false;
                    windowStart++;
                }
                existence[c] = true;
            }
            
            sol = max(sol, i - windowStart + 1);
        }
        
        return sol;
        
    }
};
