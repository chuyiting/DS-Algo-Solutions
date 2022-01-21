//
//  417-pacific-atlantic-water-flow.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/21.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    int m;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for (int i = 0; i < n; i++) {
            int j = 0;
            if (visited[i][j]) continue;
            dfs(heights, i, j, pacific, visited);
        }
        
        for (int j = 0; j < m; j++) {
            int i = 0;
            if (visited[i][j]) continue;
            dfs(heights, i, j, pacific, visited);
        }
        
        for (auto& sub : visited) {
            std::fill(sub.begin(), sub.end(), false);
        }
        
        for (int i = 0; i < n; i++) {
            int j = m-1;
            if (visited[i][j]) continue;
            dfs(heights, i, j, atlantic, visited);
        }
        
        for (int j = 0; j < m; j++) {
            int i = n-1;
            if (visited[i][j]) continue;
            dfs(heights, i, j, atlantic, visited);
        }
        
        vector<vector<int>> sol;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> pos{ i, j };
                    sol.push_back(pos);
                }
            }
        }
        return sol;
        
    }
    
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean, vector<vector<bool>>& visited) {
        if (visited[i][j]) return;
        
        visited[i][j] = true;
        ocean[i][j] = true;
        
        // right
        if (i+1 < n && heights[i][j] <= heights[i+1][j] && !visited[i+1][j]) {
            dfs(heights, i+1, j, ocean,visited);
        }
        
        // left
        if (i-1 > -1 && heights[i][j] <= heights[i-1][j] && !visited[i-1][j]) {
            dfs(heights, i-1, j, ocean,visited);
        }
        
        // top
        if (j-1 > -1 && heights[i][j] <= heights[i][j-1] && !visited[i][j-1]) {
            dfs(heights, i, j-1, ocean, visited);
        }
        
        // bottom
        if (j+1 < m && heights[i][j] <= heights[i][j+1] && !visited[i][j+1]) {
            dfs(heights, i, j+1, ocean, visited);
        }
        
    }
    
    
};
