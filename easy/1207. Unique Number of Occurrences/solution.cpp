// https://leetcode.com/problems/unique-number-of-occurrences
// easy
// #array, #hash-table

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr){
        std::unordered_map<int, int> map;
        std::unordered_map<int, bool> occ;
        bool retval = true;
        for (int num: arr){
            if(map.find(num) == map.end()){
                map[num] = 1;
            } else map[num]++;
        }
        for (auto m: map){
            if(occ.find(m.second) == occ.end())
                occ[m.second] = true;
            else{
                retval = false;
                break;
            }
        }
        return retval;
    }
};

int main(){
    std::vector<int> v1 = {1,2,2,1,1,3};
    bool res = Solution().uniqueOccurrences(v1);
    std::cout << std::boolalpha << res << std::endl;

    
}

