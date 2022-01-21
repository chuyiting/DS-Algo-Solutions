//
//  98-validate-binary-search-tree.cpp
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
    bool isValidBST(TreeNode* root) {
        vector<int> inOrderSeq = inOrderTraversal(root);
        
        for (int i = 1; i < inOrderSeq.size(); i++) {
            if (inOrderSeq[i] <= inOrderSeq[i-1]) return false;
        }
        return true;
        
    }
    
    vector<int> inOrderTraversal(TreeNode *root) {
        TreeNode *curr = root;
        stack<TreeNode*> stack;
        vector<int> seq;
        
        while (curr || !stack.empty()) {
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            seq.push_back(curr->val);
            curr = curr->right;
        }
        return seq;
    }
    
    
};

