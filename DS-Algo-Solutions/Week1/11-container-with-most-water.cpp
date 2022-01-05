//
//  11-container-with-most-water.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/5.
//

#include <stdio.h>
#include <vector>

// brute force O(n^2)`
class Solution1 {
public:
    int maxArea(std::vector<int>& height) {
        int maxA = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int h = std::min(height[i], height[j]);
                int w = j - i;
                maxA = std::max(h * w, maxA);
            }
        }
        return maxA;
    }
};

// clever trick O(n)

class Solution2 {
public:
    int maxArea(std::vector<int>& height) {
        int maxA = 0, i = 0, j = ((int) height.size()) - 1;
        while (j > i) {
            int w = j - i;
            int h = std::min(height[i], height[j]);
            maxA = std::max(w * h, maxA);
            if (height[i] < height[j]) i++;
            else j--;
        }
        
        return maxA;
    }
};
