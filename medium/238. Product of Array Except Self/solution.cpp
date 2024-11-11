// https://leetcode.com/problems/product-of-array-except-self
// medium
// #array, #prefix-sum

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefix(n,1);
        std::vector<int> suffix(n,1);
        std::vector<int> ans(n,1);
        int j = 0;
        for(int i = 1; i < n; ++i){
            j = n - i-1;
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[j] = suffix[j+1] * nums[j+1];
        }
        for(int i = 0; i < n; ++i) ans[i] = prefix[i] * suffix[i];
        return ans;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {1,2,3,4};
    nums = {-1,1,0,-3,3};
    for ( auto v: Solution().productExceptSelf(nums)){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
