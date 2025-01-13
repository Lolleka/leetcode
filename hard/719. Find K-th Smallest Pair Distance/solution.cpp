// https://leetcode.com/problems/find-k-th-smallest-pair-distance
// hard
// #array, #two-pointers, #binary-search, #sorting

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class Solution {
    int countPairs(std::vector<int>& nums, int diff){
        // use sliding window
        int i=0; int j=1;
        int n = 0;
        while(i < j && j < nums.size()){
            if(nums[j] - nums[i] <= diff) {
                n += j-i;
                j++;
            }else{
                if(i == j-1) j++;
                i++;
            }
        }
        return n;
    }
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        // sort nums array in increasing order 
        std::sort(nums.begin(), nums.end());
        int i=0, j = nums.size()-1;
        int n_a = 0, n_b = 0, n_c = 0;
        // assume minimum differnce of 0;
        int diff_a = 0;
        // calculate maximum difference as nums[nums.size()-1]-nums[0]
        int diff_b = nums[j] - nums[i];
        int diff_c = 0;
        // perform binary search
        int max_diff_c = diff_c;
        while(true){
            std::cout << "diff_a: " << diff_a << std::endl;
            std::cout << "diff_b: " << diff_b << std::endl;
            diff_c = (diff_b + diff_a) / 2;
            std::cout << "diff_c: " << diff_c;
            // for each diff_c, count how many pairs
            // produce nums[j] - nums[i] <= diff_c
            n_c = countPairs(nums, diff_c);
            std::cout << ", n_c: " << n_c << std::endl << "---" << std::endl;
            if(n_c >= k)
                max_diff_c = diff_c;

            if (diff_a == diff_b) break;
            if(n_c >= k){
                // too many pairs, reduce diff_c by lowering the diff_b
                diff_b = diff_c;
            }else{
                diff_a = diff_c+1;
            }
            
        }
        return max_diff_c;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {1,6,1};
    int k = 3;
    std::cout << std::boolalpha << Solution().smallestDistancePair(nums, k) << std::endl;
    return 0;
}
