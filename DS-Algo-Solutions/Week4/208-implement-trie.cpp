//
//  208-implement-trie.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    vector<Trie*> children;
    bool flag = false;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->flag = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); i++) {
            int id = (int) word.at(i) - 'a';
            if (!curr->children[id]) {
                curr->children[id] = new Trie();
            }
            curr = curr->children[id];
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (auto& ch: word) {
            int id = (int) ch - 'a';
            if (!curr->children[id]) {
                return false;
            }
            curr = curr->children[id];
        }
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (auto& ch: prefix) {
            int id = (int) ch - 'a';
            if (!curr->children[id]) {
                return false;
            }
            curr = curr->children[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
