//
//  1-two-sum.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/20.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            
            if (map.find(target - nums[i]) != map.end()) {
                return vector<int>{map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        
        return vector<int>{};
       
    }
};
