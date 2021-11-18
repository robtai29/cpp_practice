/******************************************************************************
https://leetcode.com/problems/binary-tree-paths/

11.17.2021
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        
        vector<string> res;
        stack<TreeNode*> tStack;
        stack<string> sStack;
        tStack.push(root);
        sStack.push("");
        
        while (!tStack.empty()){
            TreeNode* current = tStack.top();
            tStack.pop();
            string path = sStack.top();
            sStack.pop();
            path += to_string(current -> val);
            if(current -> left == nullptr && current -> right == nullptr){
                res.push_back(path);
            }
            if (current -> left){
                tStack.push(current-> left);
                sStack.push(path + "->");
            }
            if (current -> right){

                tStack.push(current-> right);
                sStack.push(path + "->");
            }   
        }
            return res;
        }
    };

/*
class Solution {
private:
    void binaryTreePaths(TreeNode* node, vector<string>& v, string str){
        if (node == nullptr){
            
            return;
        }
        
        str = str + to_string(node-> val);
    
         if (node -> left == nullptr && node -> right == nullptr){
            v.push_back(str);
             return;
        }
        str = str + "->";
        binaryTreePaths(node -> left, v, str);
        binaryTreePaths(node -> right, v, str);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        vector<string> res;

        binaryTreePaths(root, res, "");
        return res;
    }
};
*/