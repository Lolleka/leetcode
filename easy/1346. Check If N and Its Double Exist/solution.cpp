// https://leetcode.com/problems/check-if-n-and-its-double-exist
// easy
// #array, #hash-table, #two-pointers, #binary-search, #sorting

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {
        std::unordered_map<int, int> map;
        /*std::sort(arr.begin(); arr.end());*/
        for(int i = 0; i<arr.size(); ++i){
            if(arr[i] % 2 == 0){
                auto it_j = map.find(arr[i] / 2);
                if(it_j != map.end()) return true;
            }
            auto it_j = map.find(arr[i] * 2);
            if(it_j != map.end()) return true;
            map[arr[i]] = i;
        }
        return false;
    }
};


int main (int argc, char *argv[]) {
    std::vector<int> arr = {10,2,5,3};
    arr = {3,1,7,11};
    std::cout << std::boolalpha << Solution().checkIfExist(arr) << std::endl;
    return 0;
}
