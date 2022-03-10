/******************************************************************************
https://leetcode.com/problems/nested-list-weight-sum-ii/

1.26.2022
*******************************************************************************/
class Solution {
private:
    void dfsHelper(vector<NestedInteger>& list, int depth, vector<int>& vect){
        //base case
        if (vect.size() == depth){
            vect.push_back(0);
        }

        for (NestedInteger child : list){
            if (child.isInteger()){
                vect[depth] += child.getInteger();
            }else{
                dfsHelper(list.getList(), depth + 1, vect);
            }
        }
    }

public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> vect;
        dfsHelper(nestedList, 0, vect);
        int res=0
        for (int i = vect.size() -1, weight = 1; i >= 0; i--, weight++){
            res += vect[i] * weight;
        }
            return res;
    }
};