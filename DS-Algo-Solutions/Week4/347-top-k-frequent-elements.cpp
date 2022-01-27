//
//  347-top-k-frequent-elements.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/27.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, uint32_t> count;
        for (auto &it: nums) {
            if (count.find(it) == count.end()) {
                count[it] = 1;
            } else {
                count[it]++;
            }
        }
        
        vector<pair<int, int>> count_vec;
        for (auto &it: count) {
            count_vec.push_back(it);
        }
        sort (count_vec.begin(), count_vec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
            return p1.second > p2.second;
        });
        
        vector<int> sol;
        for (int i = 0; i < k; i++) {
            sol.push_back(count_vec[i].first);
        }
        
        return sol;
        
    }
    
};

