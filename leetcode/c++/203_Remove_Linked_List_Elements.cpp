/******************************************************************************
https://leetcode.com/problems/remove-linked-list-elements/

8.3.2021
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr){
            return head;
        }
        
        while (head != nullptr && head-> val == val){
            ListNode* temp = head;
            
            head = head -> next;
            delete temp;
        }
        
        ListNode* current = head;
        
        while(current != nullptr){
            if (current -> next != nullptr && current-> next -> val == val){
                ListNode* temp = current -> next;
                current-> next = current-> next-> next;
                delete temp;
                
            }else{
            
            current = current-> next;
            }
        }
        
        return head;
    }
};

/*
void removeHelper(ListNode *&node, int val) {
	if (node == nullptr){
        return;
    } 
		if (node->val == val) {
		    ListNode* temp = node;
			node = node->next;
            delete temp;
			removeHelper(node, val);
		} else {
			removeHelper(node->next, val);
		}
	
}

ListNode *removeElements(ListNode *head, int val) {
	removeHelper(head, val);

	return head;
}
*/

/*
ListNode *removeElements(ListNode *head, int val) {
	if (head == nullptr){
        return head;
    }

	if (head -> val == val){
        ListNode* temp = head;
        head = head -> next;
        delete temp;
        head = removeElements(head, val);
    }else{
        head-> next = removeElements(head -> next, val);
    }
    
    return head;
}
*/