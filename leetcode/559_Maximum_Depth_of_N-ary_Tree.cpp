/******************************************************************************
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

10.26.21
*******************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr){
            return 0;
        }
        
        int height = 0;
        for (Node* child : root -> children){
            height = max(height, maxDepth(child));
        }
        return height + 1;
    }
};