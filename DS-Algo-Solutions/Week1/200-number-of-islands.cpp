//
//  200.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/9.
//

#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = (int) grid[0].size();
        int sol = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    exploreIsland(make_pair(i, j), grid, visited, m, n);
                    sol++;
                }
            }
        }
        return sol;
    }
    
    void exploreIsland(pair<int, int> start, vector<vector<char>>& grid, vector<vector<int>>& visited, int m, int n) {
        stack<pair<int, int>> frontier;
        frontier.push(start);
        while (!frontier.empty()) {
            pair<int, int> curr = frontier.top();
            frontier.pop();
            
            if (grid[curr.first][curr.second] != '1') continue;
            if (visited[curr.first][curr.second]) continue;
            
            visited[curr.first][curr.second] = 1;
            if (curr.first - 1 >= 0) {
                pair<int, int> node(curr.first - 1, curr.second);
                frontier.push(node);
            }
            if (curr.first + 1 < m) {
                pair<int, int> node(curr.first + 1, curr.second);
                frontier.push(node);
            }
            if (curr.second - 1 >= 0) {
                pair<int, int> node(curr.first, curr.second - 1);
                frontier.push(node);
            }
            if (curr.second + 1 < n) {
                pair<int, int> node(curr.first, curr.second + 1);
                frontier.push(node);
            }
        }
        
    }

    
    
};

