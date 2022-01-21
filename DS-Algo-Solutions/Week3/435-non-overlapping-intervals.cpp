//
//  435-non-overlapping-intervals.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/22.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by starting time in descending order
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        
        int sol = 0;
        vector<int>& curr = intervals[0];
        // greedily select interval
        for (int i = 1; i < intervals.size(); i++) {
            // overlap
            if (intervals[i][1] > curr[0]) {
                sol++;
                continue;
            }
            curr = intervals[i];
        }
             
        return sol;
            
    }
};
