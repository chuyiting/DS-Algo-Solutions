//
//  297-serialize-and-deserialize-binary-tree.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/22.
//

#include <stdio.h>
#include <string>
#include <sstream>
#include <iterator>
#include <queue>
#include "297-serialize-and-deserialize-binary-tree.h"

using namespace std;


// Encodes a tree to a single string.
string Codec::serialize(TreeNode* root) {
    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (!curr) {
            result.push_back("nil");
            continue;
        }
        result.push_back(to_string(curr->val));
        q.push(curr->left);
        q.push(curr->right);
    }
    
    for (int i = result.size()-1; i >= 0; i--) {
        if (result[i] != "nil") {
            result.erase(result.begin()+i, result.end());
            break;
        }
    }
    const char* const delim = ",";
    string sol = "";
    for (vector<string>::const_iterator ii = result.begin(); ii != result.end(); ++ii) {
        sol = sol + (*ii);
        if (ii+1 != result.end()) {
            sol = sol + delim;
        }
    }
    return sol;
}

// Decodes your encoded data to tree.
TreeNode* Codec::deserialize(string data) {
    queue<string> valq;
    const char* const delim = ",";
    size_t pos = 0;
    while ((pos = data.find(delim)) != string::npos) {
        valq.push(data.substr(0, pos));
        data.erase(0, pos+1);
    }
    if (data != "") {
        valq.push(data);
    }
    
    queue<TreeNode*> ptq;
    TreeNode *sol = nullptr;
    ptq.push(sol);
    while (!valq.empty()) {
        TreeNode *curr = ptq.front();
        ptq.pop();
        
        string val = valq.front();
        valq.pop();
        
        // root
        if (!curr && val != "nil") {
            TreeNode *node = new TreeNode(atoi(val.c_str()));
            ptq.push(node);
            sol = node;
            continue;
        }
        
        if (val != "nil") {
            TreeNode *left = new TreeNode(atoi(val.c_str()));
            curr->left = left;
            ptq.push(left);
        }
        
        if (!valq.empty()) {
            string val2 = valq.front();
            valq.pop();
            
            if (val2 != "nil") {
                TreeNode *right = new TreeNode(atoi(val2.c_str()));
                curr->right = right;
                ptq.push(right);
            }
        }
        
    }
    return sol;
    
}



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

