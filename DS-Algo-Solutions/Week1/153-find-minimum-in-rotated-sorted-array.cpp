//
//  153-find-minimum-in-rotated-sorted-array.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/5.
//

#include <stdio.h>
#include <vector>


class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int i = 0, j = nums.size() - 1, mid = (i + j) / 2;
       
        while (j > i) {
            if (j - i + 1 == 2) {
                return std::min(nums[i], nums[j]);
            }
            
            mid = (i + j) / 2;
            if (nums[j] > nums[i]) {
                return nums[i];
            }
            
            if (nums[mid] > nums[i]) {
                i = mid;
            } else {
                j = mid;
            }
        }
        
        return nums[i];
    }
};
