// https://leetcode.com/problems/single-number
// easy
// #array, #bit-manipulation

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void printBinary(unsigned int n){
    for (int i=sizeof(int)*8-1; i >= 0; i--)
        std::cout << (((1 << i) & n) > 0 ? 1 : 0);
    std::cout << std::endl;
}

class MySolution {
public:
    int singleNumber(std::vector<int> nums) {
        int l = nums.size();
        if (l == 1) return nums[0];
        assert((l-1) % 2 == 0);
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<l-2; i+=2){
            if (nums[i+1] != nums[i]) return nums[i];
        }
        return nums[l-1];
    }
};


// this was the intended solution, using xor
// the bit flips eventually bring the int variable
// to 0, except for the missing element, which remains in the mask
class Solution {
public:
    int singleNumber(std::vector<int> nums) {
        int missing = 0;
        for(int n: nums){
            missing = missing ^ n;
        }
        return missing;
    }
};


int main (int argc, char *argv[]) {
    std::vector<int> v{2,1,4,1,4};
    int n = Solution().singleNumber(v);
    std::cout << n << std::endl;
    return 0;
}
