/******************************************************************************
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

6.25.2021
*******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        
        ListNode* current = head;
        
        while(current != nullptr){
            ListNode* nextNode = current-> next;
            if (nextNode != nullptr && nextNode-> val == current->val){
                current-> next = nextNode-> next;
                delete nextNode;
            }else{
            current = current-> next;
            }
        }
        
        return head;
    }
};