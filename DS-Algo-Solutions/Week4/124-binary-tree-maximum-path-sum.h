//
//  124-binary-tree-maximum-path-sum.h
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#ifndef _24_binary_tree_maximum_path_sum_h
#define _24_binary_tree_maximum_path_sum_h


#endif /* _24_binary_tree_maximum_path_sum_h */

#include <unordered_map>
#include <utility>

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
    unordered_map<TreeNode*, pair<int, int>> maxPath;
    int maxPathSum(TreeNode* root);
    void calMaxPath(TreeNode* root);
};



