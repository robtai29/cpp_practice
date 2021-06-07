/******************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was recently asked by Google.
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//brute approach
bool twoNums1(vector<int> v, int k){
    if (v.size() < 2){
        return false;
    }

    for (int i = 0; i+1 < v.size(); i++){
        for (int j = i + 1; j < v.size(); j++){
            if (v[i] + v[j] == k){
                return true;
            }
        }
    }

return false;
}

bool twoNums2(vector<int> v, int k){

    return false;
}


int main(){

    vector<int> v1{1, 2, 3, 4, 5, 6};
    int k = 0;

    bool answer = twoNums1(v1, k);

    cout << answer << endl;


}