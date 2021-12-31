/******************************************************************************
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

12.29.2021
*******************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr){
            return root;
        }
        //because this is a perfect binary tree; if a node has a left, it must also have a left child
        if (root -> left && root -> right){
            root -> left -> next = root -> right;
        }
        //need to connect a right child with the left child right next to it
        if (root -> next != nullptr && root -> right){
            root -> right -> next = root -> next -> left;
        }
        connect(root -> left);
        connect(root -> right);
        return root;
    }
};