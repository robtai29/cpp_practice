/******************************************************************************
https://leetcode.com/problems/merge-two-sorted-lists/

12.30.2021
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //use dummy node to simplify things
        ListNode dummy(-1);
        ListNode* current = &dummy;
        
        while(list1 != nullptr && list2 != nullptr){
            if (list1 -> val < list2 -> val){
                current-> next = list1;
                list1 = list1 -> next;
            }else{
                current -> next = list2;
                list2 = list2 -> next;
            }
            current = current -> next;
        }
        
        current -> next = list1 != nullptr ? list1 : list2;
        return dummy.next;
    }
};
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
*/

/*
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
*/