// https://leetcode.com/problems/successful-pairs-of-spells-and-potions
// medium

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::vector<int> pairs(spells.size(), 0);
        std::sort(potions.begin(), potions.end());
        for(int i=0; i< spells.size(); ++i){
            int a = 0, b = potions.size()-1;
            int c = 0;
            double target = double(success)/spells[i];
            /*std::cout << "target: " << target << std::endl;*/
            if (potions[potions.size()-1] < target) pairs[i] = 0;
            else{
                while(true){
                /*std::cout << "a: " << a << ", b: " << b << std::endl;*/
                    if (b == a+1 || b == a) break;
                    c = (a+b)/2;
                    if (potions[c] < target) a = c; 
                    else b = c;
                }

                if ( potions[a] >= target ) c = a;
                else if (potions[b] >= target) c = b;
                else c = potions.size();
                while (c>0 && potions[c-1] >= target) c--;
                /*std::cout << c << std::endl;*/
                pairs[i] = potions.size() - c;
            }
        }
        return pairs;
    }
};

int main (int argc, char *argv[]) {
    /*std::vector<int> spells = {5,1,3};*/
    /*std::vector<int> potions = {1,2,3,4,5};*/
    /*int val = 7;*/
    /*std::vector<int> spells = {3,1,2};*/
    /*std::vector<int> potions = {8,5,8};*/
    /*int val = 16;*/
    /*std::vector<int> spells = {15,8,19};*/
    /*std::vector<int> potions = {38,36,23};*/
    /*int val = 328;*/
    std::vector<int> spells = {16,13,7,36,16,25,22,18,29};
    std::vector<int> potions = {38,25};
    int val = 328;
    std::vector<int> pairs = Solution().successfulPairs(spells, potions, val); 
    for(int i: pairs)
        std::cout << i << ", ";
    std::cout << std::endl;
    
    return 0;
}
