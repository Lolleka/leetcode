// https://leetcode.com/problems/find-the-highest-altitude
// easy

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int max_alt = 0;
        int alt = 0;
        for (int g: gain){
            alt += g;
           if(alt > max_alt) max_alt = alt; 
        }
        return max_alt;
    }
};


int main(){
    std::vector<int> v1 = {-5,1,5,0,-7};
    std::vector<int> v2 = {-4,-3,-2,-1,4,3,2};
    std::cout << Solution().largestAltitude(v1) << std::endl;
    std::cout << Solution().largestAltitude(v2) << std::endl;
}
