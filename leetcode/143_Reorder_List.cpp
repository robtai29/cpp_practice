/******************************************************************************
https://leetcode.com/problems/reorder-list/

1.14.2022, 1.16.2022
*******************************************************************************/

class Solution {
private:
ListNode* findMiddle(ListNode* head){
    if (head == nullptr || head -> next == nullptr){
        return head;
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    
    while (fast != nullptr && fast -> next != nullptr){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow;
}
    
 ListNode* reverse(ListNode* head){
     if (head == nullptr || head -> next == nullptr){
         return head;
     }
     
     ListNode* current = head -> next;
     ListNode* prev = head;
     prev -> next = nullptr;
     while (current != nullptr){
         ListNode* nxt = current -> next;
         current -> next = prev;
         prev = current;
         current = nxt;
     }
     
     return prev;
 }
    
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head-> next == nullptr|| 
            head -> next -> next == nullptr){
            return;
        }
        
        ListNode* middle = findMiddle(head);
        ListNode* second = reverse(middle);
        
        ListNode* current = head;
        while(current != nullptr && second != nullptr){
            
            ListNode* temp = second -> next;
            second -> next = current -> next;
            current -> next =  second;
            
            current = second -> next;
            second = temp;
        }
        
        if (second == nullptr){
            current -> next = second;
        }
        
    }
};

/*
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
*/