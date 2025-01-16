// https://leetcode.com/problems/two-sum
// easy
// #array, #hash-table

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> retval = {0, 0};
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i+1; j < nums.size(); ++j){
                if (nums[i] + nums[j] == target){
                    retval[0] = i; retval[1] = j; return retval;
                }
            }
        }
        return retval;
    }
};

class Solution2{
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complement;
        std::vector<int> retval = {0, 0};
        for(int i = 0; i < nums.size(); ++i){
            auto c = complement.find(target-nums[i]);
            if (c != complement.end()){
                retval[1] = i;
                retval[0] = (*c).second;
                break;
            }else{
                complement[nums[i]] = i;
            }
            
        }
        return retval;
    }

};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {2,7,11,15};
    nums = {3,2,4};
    int target = 6;
    auto retval = Solution2().twoSum(nums, target);
    std::cout << retval[0] << ", " << retval[1] << std::endl;
    return 0;
}
