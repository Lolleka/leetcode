// https://leetcode.com/problems/find-the-difference-of-two-arrays
// easy
// #array, #hash-table

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,
                                                 std::vector<int>& nums2) {
        std::unordered_map<int, bool> nums1_map;
        std::unordered_map<int, bool> nums2_map;
        std::vector<int> v1;
        std::vector<int> v2;
        for (int num: nums1){
            nums1_map[num] = true;
        }
        for (int num: nums2){
            nums2_map[num] = true;
        }
        for (const auto& n : nums1_map){
            if(nums2_map.find(n.first) == nums2_map.end())
                v1.push_back(n.first);
        }

        for (const auto& n : nums2_map){
            if(nums1_map.find(n.first) == nums1_map.end())
                v2.push_back(n.first);
        }
        std::vector<std::vector<int>> res = {v1, v2};
        return res;
    }
};

int main(){
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = {2,4,6};
    std::vector<std::vector<int>> res = Solution().findDifference(v1, v2);
    for (auto num: res[0])
        std::cout << num << ", ";
    std::cout << std::endl;
    for (auto num: res[1])
        std::cout << num << ", ";
    std::cout << std::endl;

    
}

