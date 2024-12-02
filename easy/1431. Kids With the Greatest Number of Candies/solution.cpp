// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
// easy
// #array

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int m = *std::max_element(candies.begin(), candies.end());
        std::vector<bool> result(candies.size(), false);
        for(int i=0; i<result.size(); i++){
            result[i] = (candies[i]+extraCandies >= m);
        }
        return result;

    }
};


int main (int argc, char *argv[]) {
    std::vector<int> candies{2,3,5,1,3};
    int extraCandies = 3;
    auto result = Solution().kidsWithCandies(candies, extraCandies);
    for(bool m:result){
        std::cout << std::boolalpha << m << ", " << std::endl;
    }
    return 0;
}
