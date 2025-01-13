// https://leetcode.com/problems/candy
// hard
// #array, #greedy
#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int i = 0;
        std::vector<int> candies(ratings.size(), 1);
        if(ratings.size() == 1) return 1;
        if(ratings[0] > ratings[1]) candies[0]++;
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }
        for(auto c:candies)
            std::cout << c << ", ";
        std::cout << std::endl;
        /*if(ratings[ratings.size()-2] > ratings[ratings.size()-1]) candies[0]++;*/
        for(int i = ratings.size()-1; i > 0; --i){
            if(ratings[i-1] > ratings[i] && candies[i-1] < candies[i]){
                candies[i-1] = candies[i]+1;
            }
        }
        for(auto c:candies)
            std::cout << c << ", ";
        std::cout << std::endl;
        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> ratings = {1,3,4,5,2};
        for(auto r:ratings)
            std::cout << r << ", ";
        std::cout << std::endl;
    std::cout << Solution().candy(ratings) << std::endl;
    return 0;
}
