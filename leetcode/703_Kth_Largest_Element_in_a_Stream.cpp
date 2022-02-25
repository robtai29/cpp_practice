/******************************************************************************
https://leetcode.com/problems/kth-largest-element-in-a-stream/

2.20.22
*******************************************************************************/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int cap;
public:
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for (int num : nums){
            min_heap.push(num);
            if (min_heap.size() > k){
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size() > cap){
            min_heap.pop();
        }
        return min_heap.top();
    }
};