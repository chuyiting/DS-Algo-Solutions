//
//  207-course-schedule.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/27.
//

#include <stdio.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        vector<vector<int>> graph(numCourses);
        for (auto &it: prerequisites) {
            graph[it[0]].push_back(it[1]);
        }
        
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)  {
            if (!visited[i] && graph[i].size() > 0) {
                vector<bool> tmp_visited(numCourses, false);
                if (hasCycle(graph, visited, tmp_visited, i)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // use simple dfs to detect cycle
    bool hasCycle(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& tmp_visited, int curr) {
        visited[curr] = true;
        
        tmp_visited[curr] = true;
        for (int n: graph[curr]) {
            if (tmp_visited[n]) {
                return true;
            }
            if (!visited[n] && hasCycle(graph, visited, tmp_visited, n)) {
                return true;
            }
        }
        tmp_visited[curr] = false;
        return false;
        
    }
};

