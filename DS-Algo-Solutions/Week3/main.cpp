//
//  main.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/22.
//

#include <stdio.h>
#include "297-serialize-and-deserialize-binary-tree.h"
#include <iostream>

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Codec c;
    TreeNode *sol = c.deserialize(c.serialize(root));
    cout << sol->right->left->val;
}
