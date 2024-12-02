// https://leetcode.com/problems/max-number-of-k-sum-pairs
// medium
//  #array, #hash-table, #two-pointers, #sorting

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int count = 0;
        if (nums.size() <= 1) return 0;
        // first sort the array
        std::sort(nums.begin(), nums.end());
        // set first iterator at begin
        std::vector<int>::iterator it1 = nums.begin();
        // set second iterator at furthest number < k;
        std::vector<int>::iterator it2 = nums.end()-1;
        // iterate till it2 == it2
        while(it2 > it1){
            if (*it2 + *it1 == k){
                count++;
                it2--;
                it1++;
            }else if(*it2 + *it1 > k){
                it2--;
            }else{
                it1++;
            }
        }
        return count;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums{3,1,3,4,3}; int k = 6;
    std::cout << Solution().maxOperations(nums, k) << std::endl;
    return 0;
}
