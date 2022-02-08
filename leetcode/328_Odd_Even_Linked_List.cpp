/******************************************************************************
https://leetcode.com/problems/odd-even-linked-list/

2.4.2022
**************************************************/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr || head -> next -> next == nullptr){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenHead = even;
        
        while (even && even -> next){
            
            odd-> next = even -> next;
            even -> next = odd-> next -> next;
            
            odd = odd -> next;
            even = even -> next;
        }
        
        odd -> next = evenHead;
        return head;
        
    }
};