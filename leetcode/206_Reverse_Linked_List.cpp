/******************************************************************************
https://leetcode.com/problems/reverse-linked-list/

9.27.2021
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
    ListNode* reverseList(ListNode* head) {
        
        if (head == nullptr){
            return head;
        }
        
        ListNode* current = head;
        ListNode* fast= current -> next;
        
        while(fast != nullptr ){
   
            ListNode* temp = fast -> next;
            fast-> next = current;
            current = fast;
            fast = temp;
        }
        head-> next = nullptr;
        head = current;
        return head;
    }
    
    /*
    ListNode* reverseList(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* para = head -> next;
        ListNode* result = reverseList(para);
        
        head -> next-> next = head;
        head -> next = nullptr;
        
        return result;
    }
    */
     
};