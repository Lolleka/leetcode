// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
// medium
// #bit-manipulation

#include <iostream>


void printBinary(unsigned int n){
    for (int i=sizeof(int)*8-1; i >= 0; i--)
        std::cout << (((1 << i) & n) > 0 ? 1 : 0);
    std::cout << std::endl;
}
class Solution {
public:
    int minFlips(int a, int b, int c) {
        unsigned int n = sizeof(int)*8;
        int mask = 0;
        int bits = 0;
        for (int i = 0; i < n; ++i){
            mask = int(1 << i);
            if (((a & mask) | (b & mask)) != (c & mask)){
                if (c & mask){
                     bits++; // need to flip one bit in a or b
                }
                else{
                    // either a or b or both have a 1 in position i
                    if ((a & mask)) bits++;
                    if ((b & mask)) bits++;

                }
            }
         }
         return bits;
        
    }
};

int main (int argc, char *argv[]) {
    int a=4,b=2,c=7;
    std::cout << Solution().minFlips(a,b,c) << std::endl;
    return 0;
}
