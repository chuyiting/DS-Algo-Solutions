//
//  19-remove-nth-node-from-end-of-list.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/20.
//

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int size = 0;
        while (temp) {
            size++;
            temp = temp->next;
        }
        
        int target = size - n + 1;
        
        if (target == 1) return head->next;
        
        ListNode* curr = head->next, *prev = head;
        for (int i = 0; i < target - 2; i++) {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = curr->next;
        
        return head;
        
    }
};

