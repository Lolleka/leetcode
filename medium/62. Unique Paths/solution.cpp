// https://leetcode.com/problems/unique-paths
// medium
// #math, #dynamic-programming, #dp, #combinatorics

#include <iostream>

class Solution {
    long long C(long long n, long long r) 
    {
        long long f = 1; // Optimize with regFunction
        for(auto i = 0; i < r;i++)
            f = (f * (n - i)) / (i + 1);
        return f ; 
    }
public:
    int uniquePaths(int m, int n) {
        // gotta calculate pascal's triangle
        if (m > n)
        return C(n+m-2,n-1);
        return C(n+m-2,m-1);
    }
};

int main (int argc, char *argv[]) {

    std::cout << Solution().uniquePaths(3, 2);
    
    return 0;
}
