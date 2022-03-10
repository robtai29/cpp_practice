/******************************************************************************
https://leetcode.com/problems/average-of-levels-in-binary-tree/

10.23.21
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr){
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            long sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                sum += current -> val;
                if (current -> left != nullptr){
                    q.push(current -> left);
                }
                if (current -> right != nullptr){
                    q.push(current -> right);
                }
                
            }
            double val = (double)sum /size;
            res.push_back(val);
            
        }
        return res;
    }
};