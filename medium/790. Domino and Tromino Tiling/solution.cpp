// https://leetcode.com/problems/domino-and-tromino-tiling
// medium
// #dynamic-programming, #dp

#include <iostream>
#include <vector>

// TODO: GO BACK AND STUDY THIS SOLUTION

class Solution {
public:
    const int mod= 1e9 + 7;
    int dp[1001] = {};
    int numTilings(int n) {
         if(n <= 2)return n;
         if(n == 3)return 5;
         return dp[n]?dp[n]:dp[n] = ((numTilings(n-1)*2)%mod + (numTilings(n-3))%mod)%mod;
        // attempt at an explanation:
        // for f(n-1) we can have all configurations for n-1 and their flipped version
        // for f(n-3) we can have all configurations fdor n-3 taken one time only
        // because the other configs have already been counted in the previous step
        //
    }
};

int main (int argc, char *argv[]) {
    int n = 5;
    std::cout << Solution().numTilings(n) << std::endl;   
    return 0;
}
