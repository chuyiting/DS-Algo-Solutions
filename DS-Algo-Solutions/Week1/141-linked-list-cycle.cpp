//
//  141-linked-list-cycle.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/4.
//


#include<set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        std::set<ListNode*> visited;
        ListNode* curr = head;
        while (curr != NULL) {
            if (visited.count(curr)) {
                return true;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
        
    }
};

