//
//  105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/22.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> inorder_pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_pos[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int p_start, vector<int>& inorder, int i_start, int i_end) {
        int curr = preorder[p_start];
        if (i_start > i_end) return nullptr;
        if (i_start == i_end) {
            return new TreeNode(inorder[i_start]);
        }
        
        TreeNode *root = new TreeNode(curr);
        
        int mid_pos = inorder_pos[curr];
        TreeNode *left = buildTreeHelper(preorder, p_start+1, inorder, i_start, mid_pos-1);
        
        int left_tree_size = mid_pos - i_start;
        TreeNode *right = buildTreeHelper(preorder, p_start+1+left_tree_size, inorder, mid_pos+1, i_end);
        root->left = left;
        root->right = right;
        
        return root;
        
    }
};
