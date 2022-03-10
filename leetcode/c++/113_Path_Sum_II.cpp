/******************************************************************************
https://leetcode.com/problems/path-sum-ii/

11.18.2021
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
private:
    void pathSum(TreeNode* node, int targetSum, vector<int> v, vector<vector<int>>& res){
        if (node == nullptr){
            return;
        }
        
        targetSum = targetSum - node -> val;
        v.push_back(node -> val);
        
        bool isLeaf = node -> left == nullptr && node -> right == nullptr;
        if (isLeaf && targetSum == 0){
            res.push_back(v);
            return;
        }
        
        if (!isLeaf){
            pathSum(node-> left, targetSum, v, res);
            pathSum(node-> right, targetSum, v, res);
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return {};
        }
        vector<vector<int>> res;
        vector<int> vect;
        pathSum(root, targetSum, vect, res);

        return res;
    }
};