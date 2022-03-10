/******************************************************************************
https://leetcode.com/problems/nested-list-weight-sum/

1.25.2022
*******************************************************************************/

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfsHelper(nestedList, 1);
    }
    int dfsHelper(vector<NestedInteger>& list, int depth){
        int res{0};

        for (auto& ni : list){
            if (ni.isInteger() == true){
                res += ni.getInteger() * depth;
            }else{
                res += dfsHelper(ni.getList(), depth + 1);
            }

        }
        return res;
    }
};

/*
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for (auto& ni : nestedList){
            q.push(ni);
        }

        int res = 0;
        int level = 0;

        while (!q.empty()){
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++){
                NestedInteger current = q.front();
                q.pop();
                if (current.isInteger()){
                    res += current.getInteger() * level;
                }else{

                    for (NestedInteger child : current.getList()){
                        q.push(child);
                    }
                }
            }
        }

        return res;
    }
};

*/