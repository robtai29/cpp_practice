/******************************************************************************
https://leetcode.com/problems/string-to-integer-atoi/

11.19.2021
*******************************************************************************/

class Solution {
public:
    int myAtoi(string s) {
        long answer = 0;
        int index = 0;
        int n = s.size();
        if (n == 0){
            return 0;
        }
        int sign = 1;
        while (index < n && s[index] == ' '){
            index++;
        }
        if (index < n && (s[index] == '-' || s[index] == '+')){
            sign = s[index] == '+' ? 1 : -1;
            index++;
        }
        
        for (; index < n; index++){
            char ch = s[index];
            if (ch < '0' || ch > '9'){
                break;
            }
            answer = answer * 10 + ch - '0';
            if (answer * sign > INT_MAX){
                return INT_MAX;
            }
            if (answer * sign < INT_MIN){
                return INT_MIN;
            }
        }
        return answer * sign;
    }
};