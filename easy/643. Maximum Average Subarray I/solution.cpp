// https://leetcode.com/problems/maximum-average-subarray-i
// easy
// #array,  #sliding-window
#include <iostream>
#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int i = 0, j = k-1; 
        double sum = 0;
        for (int l=i; l<=j; ++l) sum += nums[l];
        double  max_average = sum/k;

        while(j < nums.size()-1){
            
            sum -= nums[i];
            i++;
            j++;
            sum += nums[j];
            if (sum/k > max_average) max_average = sum/k;
        }
        return max_average;

    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    std::cout << Solution().findMaxAverage(nums, k) << std::endl;
    return 0;
}
