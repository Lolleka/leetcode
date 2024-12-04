// https://leetcode.com/problems/find-peak-element
// medium
// #array, #binary-search

#include <iostream>
#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        // let's use binary search to achieve the O(log(n)) complexity requirement
        int a = 0;
        int b = nums.size()-1;
        int c = 0;
        if (nums[a+1] < nums[a]) return a;
        if (nums[b-1] < nums[b]) return b;
        while(true){
            c = (a+b)/2;
            std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
            if (nums[c+1] < nums[c] && nums[c-1] < nums[c]) break;
            else if(nums[c+1] > nums[c-1]) a=c;
            else b = c;
            /*else if(res == -1) b = (a+b)/2;*/
            /*else if(res == 1) a = (a+b)/2;*/
        }
        return c;

        
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {1,2,3,4,5,6,7,8,2,1}; 
    std::cout << Solution().findPeakElement(nums) << std::endl;
    return 0;
}
