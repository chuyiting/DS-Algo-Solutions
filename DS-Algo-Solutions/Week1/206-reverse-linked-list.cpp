//
//  206-reverse-linked-list.cpp
//  DS-Algo-Solutions
//
//  Created by Eddy Chu on 2022/1/4.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* curr = head;
        ListNode* next = head->next;
        while (next != nullptr) {
            ListNode* temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
        }
        
        head->next = nullptr;
        return curr;
    }
};
