/******************************************************************************
https://leetcode.com/problems/maximum-population-year/submissions/

11.18.2021
*******************************************************************************/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int year[101] = {};  //initize to 0
        
        for (auto& lifespan : logs){
            int birthYear = lifespan[0] - 1950;
            int deathYear = lifespan[1] - 1950;
            year[birthYear]++;
            year[deathYear]--;
            }
        
        int maxPopulation = year[0];
        int earliest = 0;
        for (int i = 1; i < 101; i++){
            year[i] += year[i-1];
            if (year[i] > maxPopulation){
                maxPopulation = year[i];
                earliest = i;
            }
        }
        return earliest + 1950;
        
    }
};