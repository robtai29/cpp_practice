/******************************************************************************
https://leetcode.com/problems/maximum-depth-of-binary-tree/

11.14.21
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
    //bfs
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }  
        
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node -> left){
                    q.push(node-> left);
                }
                if (node -> right){
                    q.push(node-> right);
                }
            }
            level++;
        }
            return level;
    }
};

/*
//dfs using recursion
    int maxDepth(TreeNode* root) {
       if (root == nullptr){
           return 0;
       }
        
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        
        return 1 + max(maxDepth(root-> left), maxDepth(root-> right));
    }
};
    }
*/


/*
   int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        
        int res{0};
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        
        while (!s.empty()){
            TreeNode* current = s.top().first;
            int level = s.top().second;
            res = max(res, level);
            s.pop();
            
            if (current -> left){
                s.push({current -> left, level + 1});
            }
            
            if (current -> right){
                s.push({current -> right, level + 1});
            }
        }
        return res;
    }
    */