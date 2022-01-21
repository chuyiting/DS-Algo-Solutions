//
//  226-invert-binary-tree.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/22.
//

#include <stdio.h>
#include <vector>
#include <stack>

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        
        TreeNode *right = invertTree(root->left);
        TreeNode *left = invertTree(root->right);
        
        return new TreeNode(root->val, left, right);
    }
}
