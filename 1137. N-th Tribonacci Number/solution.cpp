// https://leetcode.com/problems/n-th-tribonacci-number/
// easy

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
    /* vector<int> v; */
    /* for (int i=0; i < 100; ++i){ */
    /*     v.push_back(i); */
    /* } */
    cout << Solution().tribonacci(25) << endl;
    
    return 0;
}
