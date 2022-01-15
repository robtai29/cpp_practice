/******************************************************************************
https://leetcode.com/problems/reorder-list/

1.14.2022
*******************************************************************************/

class Solution {
public:
    void reorderList(ListNode* head) {
        //if 2 or less nodes are present, just return
        if (head == nullptr || head -> next == nullptr || head -> next -> next == nullptr){
            return;
        }
        
        ListNode* penultimate = head;
        while(penultimate -> next -> next != nullptr){
            penultimate = penultimate -> next;
        }
        
        penultimate -> next -> next = head -> next;
        head -> next = penultimate -> next;
        penultimate-> next = nullptr;
        reorderList(head -> next -> next);
        
    }
};