// https://leetcode.com/problems/house-robber
// medium
// #array, #dynamic-programming, #dp
#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) dp[i] = nums[i];
            else if (i == 1) dp[i] = std::max(nums[i], nums[i-1]);
            else dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];

    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums{2,7,9,3,1};
    nums={2,1,1,2};
    std::cout << Solution().rob(nums) << std::endl;
    return 0;
}
