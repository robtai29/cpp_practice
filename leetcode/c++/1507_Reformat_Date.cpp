/******************************************************************************
https://leetcode.com/problems/reformat-date/

9.5.2021
*******************************************************************************/
class Solution {
public:
    string reformatDate(string date) {
        int size = date.length();
        string yyyy = date.substr(size-4);
        string strArray[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string month = date.substr(size-8, 3);
        int numMonth = find(begin(strArray), end(strArray), month) - begin(strArray) + 1;
        string mm = numMonth <= 9 ? "0" + to_string(numMonth) : to_string(numMonth);
        
        string dd = isdigit(date[1]) ? date.substr(0, 2) : "0" + date.substr(0, 1);
        
        
        return yyyy + "-" + mm + "-" + dd;
    }
};