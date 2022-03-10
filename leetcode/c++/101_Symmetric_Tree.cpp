/******************************************************************************
https://leetcode.com/problems/symmetric-tree/

11.11.2021
*******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
//bfs level traversal
    public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root-> left);
        q.push(root-> right);
        while(!q.empty()){
            TreeNode* a = q.front();
            q.pop();
            TreeNode* b = q.front();
            q.pop();
           if (a == nullptr && b == nullptr){
            continue;
        }else if ( a == nullptr || b == nullptr || a-> val != b-> val){
            return false;
        }
            q.push(a-> left);
            q.push(b-> right);
            q.push(a-> right);
            q.push(b-> left);
        }
        return true;
    }
};

/*
//recursive
class Solution {
private:
    bool isSymmetric(TreeNode* l, TreeNode* r){
        if (l == nullptr && r == nullptr){
            return true;
        }else if ( l == nullptr || r == nullptr){
            return false;
        }
        
        return l-> val == r -> val && isSymmetric(l -> left, r -> right) && isSymmetric(l -> right, r -> left); 
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        return isSymmetric(root-> left, root-> right);
    }
};
*/