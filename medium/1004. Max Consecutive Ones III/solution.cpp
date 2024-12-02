// https://leetcode.com/problems/max-consecutive-ones-iii/
// medium
// #array, #binary-search, #sliding-window, #prefix-sum

#include <iostream>
#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        int a = 0, b=0;
        int j = 0;
        int max_l = 0;
        while(b < nums.size()){
            //increment b, flipping zeros until it is possible
            b++;
            if(nums[b-1] == 0){
                if (j < k){
                    // flip zero
                    j++;
                }else{
                    // flipping zero is not possible
                    // advance a till after the next zero
                    do{
                    a++;
                    }while(nums[a-1]==1);
                }
            }
            if (b-a > max_l) max_l = b-a;
        }
        return max_l;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    k=3;
    std::cout << solution.longestOnes(nums, k) << std::endl;
    return 0;
}

