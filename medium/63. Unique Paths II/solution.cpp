// https://leetcode.com/problems/unique-paths-ii/
// medium

#include <iostream>
#include <vector>

class Solution {

public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        std::vector<std::vector<long long>> dp(h, std::vector<long long>(w, 0));
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0]=1;
        for (int i = 0; i < w; ++i){
           for (int j = 0; j < h; ++j){
                if (obstacleGrid[j][i] == 0){
                    if (i > 0) dp[j][i]+=dp[j][i-1];
                    if (j > 0) dp[j][i]+=dp[j-1][i];
                } else dp[j][i] = 0;
            }
        } 
        return dp[h-1][w-1];
    }
};

int main (int argc, char *argv[]) {
    int  w = 4, h = 3;
    std::vector<std::vector<int>> grid(h, std::vector<int>(w, 0));
    grid[1][1] = 1;
    std::cout << Solution().uniquePathsWithObstacles(grid);
    return 0;
}
