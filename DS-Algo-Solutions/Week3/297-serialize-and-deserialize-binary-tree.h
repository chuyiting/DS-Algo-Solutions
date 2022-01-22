//
//  297-serialize-and-deserialize-binary-tree.h
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/22.
//

#ifndef _97_serialize_and_deserialize_binary_tree_h
#define _97_serialize_and_deserialize_binary_tree_h


#endif /* _97_serialize_and_deserialize_binary_tree_h */

#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);

};
