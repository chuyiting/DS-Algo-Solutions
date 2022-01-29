//
//  211-design-add-and-search-words-data-structure.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/29.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
public:
    unordered_map<size_t, vector<string>> dict;
    WordDictionary() {
    }
    
    void addWord(string word) {
        if (dict.find(word.size()) == dict.end()) {
            dict[word.size()] = *(new vector<string>());
        }
        dict[word.size()].push_back(word);
    }
    
    bool search(string word) {
        if (dict.find(word.size()) == dict.end()) {
            return false;
        }
        
        for (auto& str: dict[word.size()]) {
            if (is_equal(str, word)) return true;
        }
        return false;
    }
    
    bool is_equal(string word, string match) {
        for (int i = 0; i < word.size(); i++)  {
            if (match[i] == '.') continue;
            if (match[i] != word[i]) return false;
        }
        return true;
    }
};

