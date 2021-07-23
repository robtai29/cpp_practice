/******************************************************************************
https://leetcode.com/problems/swap-nodes-in-pairs/

7.23.2021
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head-> next == nullptr){
            return head;
        }
        
        ListNode* front = head-> next;
        ListNode* parameter = head-> next -> next;
        ListNode* back = head;
        front-> next = back;
        back-> next = swapPairs(parameter);
        

        return front;
    }
};