/******************************************************************************
https://leetcode.com/problems/find-smallest-letter-greater-than-target/

11.21.21
*******************************************************************************/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target){
            return letters[0];
        }
        
        int high = letters.size() -1;
        int low = 0;
        
        while (high >= low){
            int mid = low + (high - low) / 2;
            
            if (letters[mid] > target){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return letters[low];
    }
};

/*
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters[0];
        auto ptr = upper_bound(letters.begin(), letters.end(), target);
        
        return *ptr;
*/