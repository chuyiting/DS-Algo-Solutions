//
//  102-binary-tree-level-order-traversal.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        helper(root, sol, 0);
        return sol;
    }
    
    void helper(TreeNode* node, vector<vector<int>>& sol, int level) {
        if (!node) return;
        if (sol.size() < (level + 1)) {
            vector<int>* v = new vector<int>({node->val});
            sol.push_back(*v);
        } else {
            sol[level].push_back(node->val);
        }
        helper(node->left, sol, level + 1);
        helper(node->right, sol, level + 1);
    }
};
