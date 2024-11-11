// https://leetcode.com/problems/min-cost-climbing-stairs
// easy
// #array, #dynamic-programming, #DP
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int s = -1;
        int n = cost.size();
        std::vector<int> tot_cost_a(n,0);
        std::vector<int> tot_cost_b(n,0);
        tot_cost_a[0] = cost[0];
        tot_cost_b[0] = cost[0];
        tot_cost_a[1] = cost[0] + cost[1];
        tot_cost_b[1] = cost[1];
        int i = 2;
        for (; i < n; ++i){
            tot_cost_a[i] = std::min(tot_cost_a[i-1],tot_cost_b[i-1]) + cost[i];
            tot_cost_b[i] = std::min(tot_cost_a[i-2],tot_cost_b[i-2]) + cost[i];
        }
        int final_cost_a = std::min(tot_cost_a[i-1],tot_cost_b[i-1]);
        int final_cost_b = std::min(tot_cost_a[i-2],tot_cost_b[i-2]);
        return final_cost_a < final_cost_b ? final_cost_a : final_cost_b;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> cost = {10,15,20}; 
    cost = {1,100,1,1,1,100,1,1,100,1};
    cost = {841,462,566,398,243,248,238,650,989,576,361,126,334,729};
    std::cout << Solution().minCostClimbingStairs(cost) << std::endl;
    return 0;
}
