// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
// medium
// #array, #dynamic-programming, #dp

#include <iostream>
#include <vector>

class Solution1 {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int n = prices.size();
        int max_profit = 0;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        // dp matrix contains best case scenario considering buying
        // at i and selling at j
        // the result is the profit of the transaction minus the fee
        // plus the max profit made by selling at day i-1
        
        // buying and selling on day one produces a negative profit of -fee
        // so we initialize with best case of no operation
        // initialize first row which means buying (or not) on day 0 and
        // selling afterwards
        for(int j = 0; j < n; j++){
            dp[0][j] = std::max(0, prices[j]-prices[0] -fee);
            if (dp[0][j] > max_profit) max_profit = dp[0][j];
        }
        // the lower triangular half of the matrix does not make sense and is set to 0
        for (int i = 1; i < n; i++) {
            // find best case scenario up to i-1
            int m = 0;
            for(int k = 0; k < i; ++k) if (dp[k][i-1] > m) m = dp[k][i-1];
            // compute all possible cases
            for (int j = i; j < n; j++) {
                dp[i][j] = std::max(m, m + prices[j]-prices[i]-fee);
                if (dp[i][j] > max_profit) max_profit = dp[i][j];
            }
        }

        return max_profit;
    }
};

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int n = prices.size();
        std::vector<int> hold(n, 0);
        std::vector<int> not_hold(n, 0);
        hold[0]=-prices[0];
        not_hold[0]=0;

        for(int j = 1; j < n; j++){
            // for hold: best case scenario is between selling now if we do
            // hold, in which case the net asset is hold[j-1] + price[j] - fee
            // or waiting to buy if we are not holding, i.e. not_hold[j-1]
            hold[j] = std::max(hold[j-1], not_hold[j-1]-prices[j]);            
            // for not_hold: best case scenario is between buying now if we do
            // not hold, in which case the net asset is not_hold[j-1] - price[j]
            // or keeping the stocks if we are holding, i.e. hold[j-1]
            not_hold[j] = std::max(not_hold[j-1],hold[j-1]+prices[j]-fee);


        }
        return std::max(hold[n-1], not_hold[n-1]);
    }
};


int main (int argc, char *argv[]) {
    std::vector<int> prices{1,3,2,8,4,9};
    prices = {1,3,7,5,10,3};
    int fee = 2;
    std::cout << Solution().maxProfit(prices, fee) << std::endl;
    return 0;
}
