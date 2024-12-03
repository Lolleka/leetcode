// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
// medium
// #array, #dynamic-programming, #dp, #sliding-window

#include <iostream>
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int removed = 0;
        int count = 0;
        int max_count = 0;
        int i = 0; int j=1;
        while(j < nums.size()){
            if(nums[j] != 1){
                if (nums[removed] == 0) i = removed+1;
                removed = j;
            }
            count = j-i + 1 - static_cast<int>(removed >= 0);
            if (count > max_count) max_count = count;
            j++;
        }
    return max_count;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums{0,1,1,1,0,1,1,0,1};
    /*std::vector<int> nums{0,1,1,1,1,1};*/
    std::cout << Solution().longestSubarray(nums) << std::endl;
    return 0;
}
