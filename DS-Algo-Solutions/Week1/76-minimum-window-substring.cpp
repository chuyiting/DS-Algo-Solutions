//
//  76-minimum-window-substring.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/9.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include "76-minimum-window-substring.h"

using namespace std;

string Solution::minWindow(string s, string t) {
        string sol = "";
        
        int requireN = 0;
        unordered_map<char, int> req_cnt;
        for(int i = 0; i < t.size(); i++) {
            if (req_cnt.find(t.at(i)) == req_cnt.end()) {
                req_cnt[t.at(i)] = 0;
                requireN++;
            }
            req_cnt[t.at(i)]++;
        }
        
        int windowStart = 0;
        unordered_map<char, int> curr_cnt;
        for (int i = 0; i < s.size(); i++) {
            char c = s.at(i);
            // dont care about this character
            if (req_cnt.find(c) == req_cnt.end()) continue;
            
            if (curr_cnt.find(c) == curr_cnt.end()) {
                curr_cnt[c] = 0;
            }
            
            curr_cnt[c]++;
            if (curr_cnt[c] == req_cnt[c]) requireN--;
            
            if (requireN == 0) {
                if (sol == "" || i - windowStart + 1 < sol.size()) {
                    sol = s.substr(windowStart, i - windowStart + 1);
                }
                
                // move left pointer
                while (windowStart <= i) {
                    char c_to_drop = s.at(windowStart);
                    curr_cnt[c_to_drop]--;
                    windowStart++;
                    if (req_cnt.find(c_to_drop) == req_cnt.end()) {
                        if (i - windowStart + 1 < sol.size()) {
                            sol = s.substr(windowStart, i - windowStart + 1);
                        }
                        continue;
                    }
                    
                    if (curr_cnt[c_to_drop] < req_cnt[c_to_drop]) {
                        requireN++;
                        break;
                    }
                    
                    // still valid
                    if (i - windowStart + 1 < sol.size()) {
                        sol = s.substr(windowStart, i - windowStart + 1);
                    }
                }
            }
        }
        return sol;
    }
