/******************************************************************************
https://leetcode.com/problems/merge-two-binary-trees/

11.8.21
*******************************************************************************

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr){
            return root1 ? root1 : root2;
        }
        
        stack<TreeNode*> s1, s2;
        TreeNode* res = root1;
        
        s1.push(root1);
        s2.push(root2);
        
        while(!s1.empty() && !s2.empty()){
            TreeNode* node1 = s1.top();
            s1.pop();
            TreeNode* node2 = s2.top();
            s2.pop();
            
            node1-> val += node2 -> val;
            
            if (node1-> left == nullptr && node2 -> left){
                node1-> left = node2-> left;
            }else if (node1 -> left && node2 -> left){
                s1.push(node1->left);
                s2.push(node2-> left);
            }
            
            if (node1-> right == nullptr && node2 -> right){
                node1-> right = node2-> right;
            }else if (node1 -> right && node2 -> right){
                s1.push(node1->right);
                s2.push(node2-> right);
            }
            
        }
        
        return res;
    }
};

/*
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr){
            return root1 ? root1 : root2;
        }
        
        int sum = root1 -> val + root2 -> val;
        root1-> val = sum;
        root1 -> left = mergeTrees(root1-> left, root2-> left);
        root1 -> right = mergeTrees(root1-> right, root2-> right);
        
        return root1;
    }
*/