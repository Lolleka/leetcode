// https://leetcode.com/problems/find-pivot-index
// easy
// #array, #prefix-sum

#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0;
        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];
        for (int i = 0; i < nums.size(); ++i){
            if (sum - nums[i] == 2*prefix_sum) return i;
            prefix_sum += nums[i];
        }
        return -1;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {1,7,3,6,5,6};
     nums = {2,1,-1};
    std::cout  << Solution().pivotIndex(nums) << std::endl;
    
    return 0;
}
