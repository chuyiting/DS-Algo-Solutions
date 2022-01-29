//
//  572-subtree-of-another-tree.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#include <stdio.h>
#include <queue>

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->val == subRoot->val) {
                if(isEqual(curr, subRoot)) return true;
            }
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            
        }
        return false;
    }
    
    bool isEqual(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;
        
        return isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
    }
};
