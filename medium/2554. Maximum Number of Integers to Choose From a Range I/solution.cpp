// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i
// medium
// #array, #hash-table, #binary-search, #greedy, #sorting

#include <iostream>
#include <vector>
#include <set>

class Solution {
    bool isBanned(int i, std::set<int>& banned){
        for(int k: banned) if(i==k) return true;
        return false;
    }
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        int sum = 0;
        int start = n;
        int count = 0;
        // transform vector into a set
        std::set<int> bannedSet;
        for(int i: banned) bannedSet.insert(i);

        for(int i = 1; i <= n; i++){
            if (bannedSet.find(i) == bannedSet.end()){
                sum += i;
                if (sum <= maxSum) count++;
                else return count;
            }
        }
        return count;

       
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> banned = {1,6,5}; 
    int n = 5;
    int maxSum = 6;
    banned = {1,2,3,4,5,6,7}; n=8; maxSum=1;
    banned = {11}; n=7; maxSum=50;
    std::cout << Solution().maxCount(banned, n, maxSum) << std::endl;
    return 0;
}
