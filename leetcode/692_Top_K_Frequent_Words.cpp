/******************************************************************************
https://leetcode.com/problems/top-k-frequent-words/submissions/

9.25.21
*******************************************************************************/

/*
O(N) for hashmap, O(NlogK) for pq --- O(logK) each time
S(K) for hashmap, S(K) for pq
trick : whenever we have a new pair, push it to the pq first
let the pq decide the order, and then pop the top if pq.size() > k
Min-heap: return int a > int b (keep larger one)
low-alphabetical order : string a < string b (keep lower one)
*/

class Solution {
public:
    // setup minheap
    struct myCompare{
      bool operator()(pair<int, string> a, pair<int, string> b){
          return a.first > b.first ||(a.first == b.first && a.second < b.second);      
      }  
        
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string str : words){
            m[str]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, myCompare> pq;
        for (const auto& entry : m){
            pq.push({entry.second, entry.first});
        }
        
        while(pq.size() > k){
            pq.pop();
        }
        
        vector<string> res(k);
        for (int i = res.size() -1; i >= 0; i--){
            res[i] = pq.top().second;
            pq.pop();
        }
        
        return res;
    }

};

/*
class Solution {//idea: negative + pair + priority_queue 
public:
    vector<string> topKFrequent(vector<string>& words, int k) {        
        unordered_map<string, int> m;
        for(const auto& i: words) ++m[i];
        priority_queue<pair<int, string>> pq; //trick1: built-in structure pair is well-supported, no need compare
        //joke: in Chinese, we call pair, Qing Er Zi(亲儿子), or nature son, to C++ system, so spoiled, and user need to do nothing extra
 
        for(const auto& i: m){
            pq.emplace(-i.second, i.first); //trick2: use -1 to turn default max heap into min heap
            //pq.push({-i.second, i.first});// ok, but less efficient than emplace
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans(pq.size());
        for(int i = pq.size() -1; i >=0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
*/