/******************************************************************************
https://leetcode.com/problems/binary-tree-inorder-traversal/

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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        //invariant: s can not have nullptrs inside
        while(!s.empty() || current != nullptr){
            if (current != nullptr){
                s.push(current);
                current = current -> left;
            }else{
                current = s.top();
                s.pop();
                res.push_back(current -> val);
                current = current -> right;
            }
        }     
        return res;
    }
    
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        inorderTraversal(root, result);
        return result;
    }
    
    void inorderTraversal(TreeNode* node, vector<int>& v){
        if (node == nullptr){
            return;
        }
        inorderTraversal(node-> left, v);
        v.push_back(node -> val);
        
        inorderTraversal(node-> right, v);
        
        
    }
};
*/

/*
 vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr){
            return vector<int>{};
        }    
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        while(!s.empty() || current != nullptr){
            while(current != nullptr){
                s.push(current);
                current = current -> left;
            }
            
            current = s.top();
            s.pop();
            result.push_back(current -> val);
            current = current -> right;
        }
        return result;
    }
*/