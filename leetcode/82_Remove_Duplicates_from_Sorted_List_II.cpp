/******************************************************************************
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

12.24.2021
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
        if (head == nullptr || head -> next == nullptr){
            return head;
        }
        
        ListNode dummy(0);
        ListNode* result = &dummy;
        ListNode* pre = result;
        pre-> next = head;
        ListNode* current = head;
        bool duplicate = false;
        
        while(current != nullptr){
            if (current -> next != nullptr && current -> val == current -> next -> val){
                duplicate = true;
            }else{
                if (duplicate){
                    pre-> next = current -> next;
                }else{
                    pre = pre -> next;
                }
                duplicate = false;
            }
             current = current -> next;
        }
        
        return result -> next;
    }
};

/*
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head -> next == nullptr){
            return head;
        }
        
        ListNode dummy(0);
        ListNode* fakehead = &dummy;
        ListNode* pre = fakehead;
        pre-> next = head;
        
        ListNode* current = head;
        
        while (current != nullptr){
            while(current -> next != nullptr && current -> val == current -> next -> val){
                current = current -> next;
            }
            
            //check if current is not a duplicate
            if (pre-> next == current){
                pre = pre-> next;
            }else{
                pre -> next = current -> next;
            }
            current = current -> next;
        }
        
        return fakehead-> next;
    }
*/