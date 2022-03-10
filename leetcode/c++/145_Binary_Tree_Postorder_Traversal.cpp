/******************************************************************************
https://leetcode.com/problems/binary-tree-postorder-traversal/

11.16.2021
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
    //one stacks-DFS iterative
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        vector<int> res;
        stack<TreeNode*> nodesToVisit;
        nodesToVisit.push(root);
        while (!nodesToVisit.empty()){
            TreeNode* current = nodesToVisit.top();
            nodesToVisit.pop();
            res.insert(res.begin(), current -> val);
            
            if (current -> left){
                nodesToVisit.push(current -> left);
            }
            if (current-> right){
                nodesToVisit.push(current -> right);
            }
        }
        return res;
    }
};
/*
    //two stacks-DFS iterative
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        
        stack<TreeNode*> nodesToVisit;
        stack<TreeNode*> RLPreorderStack;
        vector<int> res;
        
        nodesToVisit.push(root);
        
        while(!nodesToVisit.empty()){
            TreeNode* current = nodesToVisit.top();
            nodesToVisit.pop();
            RLPreorderStack.push(current);
            if(current-> left){
                nodesToVisit.push(current-> left);
            }
            if(current-> right){
                nodesToVisit.push(current-> right);
            }
        }
        
        while(!RLPreorderStack.empty()){
            TreeNode* node = RLPreorderStack.top();
            RLPreorderStack.pop();
            res.push_back(node -> val);
        }
        return res;
    }
};
*/


/*
//recursive dfs
class Solution {
private:
    void postorderTraversal(TreeNode* node, vector<int>& v){
        if (node == nullptr){
            return;
        }
        
        postorderTraversal(node-> left, v);
        postorderTraversal(node-> right, v);
        v.push_back(node-> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorderTraversal(root, v);
        return v;
    }
};
*/