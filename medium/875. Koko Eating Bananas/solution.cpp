// https://leetcode.com/problems/koko-eating-bananas
// medium
// #array, #binary-search

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    int eat(std::vector<int>& piles, int k){
        int sum = 0;
        for(int i: piles)
            sum += (i / k) + static_cast<int>(i % k != 0);
        return sum;
    }
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // perform a binary search on speed value k
        // initially set k_max to max(piles)
        // and min_k to 1
        // on each iteration calculate the number of hours H
        // required to eat all piles as sum_i(ceil(piles[i]/k))
        // stop when H = h
        int a = 1;
        int b = *std::max_element(piles.begin(), piles.end());
        int k = 0;
        int H = 0;
        if (eat(piles, a) < h) return a;
        while(true){
            k = (a+b)/2;
            H = eat(piles, k);
            std::cout << "k: " << k << " H: " << H << std::endl;
            if (a == b-1){
                k = eat(piles, a) <= h ? a : b;
                break;
            }
            else if(H > h) a=k;
            else b=k;
        }
        return k;

    }
};

int main (int argc, char *argv[]) {
    std::vector<int> piles = {3,6,7,11};
    int h = 8;
    /*piles={30,11,23,4,20};*/
    /*h = 5;*/
    /*piles={30,11,23,4,20};*/
    /*h = 6;*/
    std::cout << Solution().minEatingSpeed(piles, h) << std::endl;
    return 0;
}
