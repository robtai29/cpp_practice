/******************************************************************************
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

6.17.21
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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* current = head;
        while (current != nullptr){
            result *= 2;
            result += current -> val;
            current = current -> next;
        }
        return result;
    }
};