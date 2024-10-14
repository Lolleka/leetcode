// https://leetcode.com/problems/move-zeroes
// easy
#include <iostream>
#include <vector>

class Solution{
public:
    void moveZeroes(std::vector<int>& nums){
        int offset=0;
        for (int i=0; i< nums.size(); ++i){
            if (nums[i]) nums[i-offset]=nums[i];
            else offset++;
        }
        for (int i=nums.size()-offset; i < nums.size(); ++i) nums[i] = 0;
    }
};

int main(){
    std::vector<int> o = {0, 1, 0 ,3, 12};
    for (int i: o) std::cout << i << " ";
    std::cout << std::endl;
    std::vector<int> v = {0, 1, 0 ,3, 12};
    Solution().moveZeroes(v);
    for (int i: v) std::cout << i << " ";
    std::cout << std::endl;
}
