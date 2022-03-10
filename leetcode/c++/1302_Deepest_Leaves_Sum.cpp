/******************************************************************************
https://leetcode.com/problems/deepest-leaves-sum/

8.8.21
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
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        
        queue<TreeNode*> q;
        int res;
        
        q.push(root);
        while(!q.empty()){
            res = 0;
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                res+= node-> val;
                if (node-> left){
                    q.push(node-> left);
                }
                if (node-> right){
                    q.push(node-> right);
                }
            }
        }
        return res;
    }
};