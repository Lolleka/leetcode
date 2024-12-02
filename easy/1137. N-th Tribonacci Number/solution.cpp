// https://leetcode.com/problems/n-th-tribonacci-number/
// easy
// #math, #dynamic-programming, #dp, #memoization

#include <iostream>
#include <vector>

using namespace std;


class Solution {
    vector<int> memo = {0, 1, 1};
public:
    int tribonacci(int n) {
        int val = 0;
        if (memo.size() > n){
            val = memo[n];
        }
        else{
            cout << n << endl;
            val = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            memo.push_back(val);
        }
        return val;
    }
};

int main(){
    cout << Solution().tribonacci(25) << endl;
    return 0;
}
