/******************************************************************************
https://leetcode.com/problems/merge-two-sorted-lists/

7.8.2021
*******************************************************************************/

class Solution {
public:
    //recursive
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr){
            return l2;
        }
        
        if (l2 == nullptr){
            return l1;
        }
    
        if (l1 -> val > l2 -> val){

            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }else{    

            l1-> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
    }

    //iterative
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (!l1){
        return l2;
    }
    
    if (!l2){
        return l1;
    }
        
    ListNode* head = nullptr;
    if (l1-> val > l2 -> val){
        head = l2;
        l2 = l2 -> next;
    }else{
        head = l1;
        l1 = l1 -> next;
    }
    
        ListNode* current = head;
        while (l1 && l2){
            
            if (l1 -> val < l2 -> val){
                current-> next = l1;
                l1 = l1-> next;
                current = current -> next;
            }else{
                current-> next = l2;
                l2 = l2 -> next;
                current = current -> next;
            }
            
        }
    
        if (!l1){
            current -> next = l2;
        }else{
            current -> next = l1;
        }
    return head;
    }



    
   
    
};