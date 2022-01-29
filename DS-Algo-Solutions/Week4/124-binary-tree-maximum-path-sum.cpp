//
//  124-binary-tree-maximum-path-sum.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#include <stdio.h>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
#include "124-binary-tree-maximum-path-sum.h"

using namespace std;

int Solution::maxPathSum(TreeNode* root) {
    calMaxPath(root);
    queue<TreeNode*> q;
    q.push(root);
    int sol = -1001;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        sol = max(sol, maxPath[curr].first + maxPath[curr].second - root->val);
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }
    return sol;
}

void Solution::calMaxPath(TreeNode* root) {
    cout << root->val << endl;
    if (!root->left && !root->right) {
        Solution::maxPath[root] = make_pair(root->val, root->val);
        return;
    }
    
    if (maxPath.find(root) == maxPath.end()) {
        maxPath[root] = make_pair(-1001, -1001);
    }
    
    // calculate lMax
    if (!root->left) {
        maxPath[root].first = root->val;
    } else {
        calMaxPath(root->left);
        
        int lChildMax = max(maxPath[root->left].first, maxPath[root->left].second);
        
        int lMax = lChildMax > 0 ? lChildMax + root->val : root->val;
        maxPath[root].first = lMax;
    }
    
    // calculate rMax
    if (!root->right) {
        maxPath[root].second = root->val;
    } else {
        calMaxPath(root->right);
        
        int rChildMax = max(maxPath[root->right].first, maxPath[root->right].second);
        
        int rMax = rChildMax > 0 ? rChildMax + root->val : root->val;
        maxPath[root].second = rMax;
        
    }

    
}

