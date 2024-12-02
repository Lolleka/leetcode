// https://leetcode.com/problems/counting-bits/
// easy
// #dynamic-programming, #dp, #bit-manipulation

#include <iostream>
#include <vector>

void printBinary(unsigned int n){
    for (int i=sizeof(int)*8-1; i >= 0; i--)
        std::cout << (((1 << i) & n) > 0 ? 1 : 0);
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<int> countBits(unsigned int n) {
        std::vector<int> result;
        result.push_back(0);
        if (n >= 1) result.push_back(1);
        for(unsigned int i = 2; i <= n; i++){
            int count = result[i >> 1] + static_cast<int>(i & 1);
            result.push_back(count);
        }
        return result;
    }
};

int main (int argc, char *argv[]) {
    auto v = Solution().countBits(10);
    for(auto i: v) std::cout << i << ", ";
    std::cout << std::endl;
    return 0;
}
