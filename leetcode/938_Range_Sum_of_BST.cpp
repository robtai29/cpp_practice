/******************************************************************************
https://leetcode.com/problems/range-sum-of-bst/

2.24.2022
*******************************************************************************/

class Solution {
public:
    //preorder traversal
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr){
            return 0;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        int sum = 0;
        while (!s.empty()){
            TreeNode* current = s.top();
            s.pop();
            
            if (current -> val >= low && current -> val <= high){
                sum += current -> val;
            }
            
            if (current -> val <= high && current -> right){
                s.push(current -> right);
            }
            
            if (current -> val >= low && current -> left){
                s.push(current -> left);
            }
            
        }
            return sum;
    }
};

/*
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr){
            return 0;
        }
        
        if (root -> val < low){
            return rangeSumBST(root -> right, low, high);
        }else if (root -> val > high){
            return rangeSumBST(root-> left, low, high);
        }else{
            return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
         }
    }
};
*/

/*
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr){
            return 0;
        }
        
        int value = root -> val >= low && root -> val <= high ? root -> val : 0;
        
        int left = 0;
        
        if (root -> val >= low){
            left = rangeSumBST(root-> left, low, high);
        }
        
        int right = 0;
        if (root -> val <= high){
            right = rangeSumBST(root-> right, low, high);
        }
        
        return value + left + right;
    }
};
*/