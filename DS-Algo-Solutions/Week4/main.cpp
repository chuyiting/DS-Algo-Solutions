//
//  main.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#include <stdio.h>
#include <iostream>
#include "124-binary-tree-maximum-path-sum.h"

using namespace std;
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    Solution sol;
    cout << sol.maxPathSum(root) << endl;
    
    return 0;
}
