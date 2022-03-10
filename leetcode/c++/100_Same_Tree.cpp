/******************************************************************************
https://leetcode.com/problems/same-tree/

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
    //dfs  preorder
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while(!s.empty()){
            TreeNode* a = s.top();
            s.pop();
            TreeNode* b = s.top();
            s.pop();
            if (a == nullptr && b == nullptr){
                continue;
            }else if (a == nullptr || b == nullptr){
                return false;
            }else{
                if (a-> val != b-> val){
                    return false;
                }
                s.push(a-> left);                
                s.push(b-> left); 
                s.push(a-> right);                
                s.push(b-> right); 
            }
        }
        return true;
    }
};
/*
    //bfs level traversal
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> nodeQueue;
        nodeQueue.push({p, q});
        while(!nodeQueue.empty()){
            pair<TreeNode*, TreeNode*> pair_ = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* a = pair_.first;
            TreeNode* b = pair_.second;
            if (a == nullptr && b == nullptr){
                continue;
            }else if (a == nullptr || b == nullptr){
                return false;
            }else{
                if (a-> val != b-> val){
                    return false;
                }
                nodeQueue.push({a-> left, b -> left});                
                nodeQueue.push({a-> right, b -> right}); 
            }
        }
        return true;
    }


*/

/*  recursion

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){
            return true;
        }else if (!p || !q){
            return false;
        }
        
        return p-> val == q -> val && isSameTree(p-> left, q-> left) && isSameTree(p-> right, q-> right);
        
    }
*/