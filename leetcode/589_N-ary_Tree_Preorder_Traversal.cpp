/******************************************************************************
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

10.29.21
*******************************************************************************/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }
        
        stack<Node*> s;
        s.push(root);
        
        while (!s.empty()){
            Node* current = s.top();
            s.pop();
            
            res.push_back(current -> val);
            
            for (int i = current -> children.size() -1; i >= 0; i--){
                if (current -> children[i] != nullptr){
                    s.push(current -> children[i]);
                }
            }
        }
            return res;
    }
};

/*
class Solution {
private:
    void preorder(Node* node, vector<int>& res){
        if (node == nullptr){
            return;
        }
        
        res.push_back(node -> val);
        for (Node* n : node -> children){
            preorder(n, res);
        }
        
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
*/