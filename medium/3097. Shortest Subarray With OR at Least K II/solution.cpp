// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii
// medium
// #array, #bit-manipulation, #sliding-window

#include <iostream>
#include <vector>
class Solution {
    unsigned int addBits(int num, int* bits, bool up = true) {
        unsigned int p = 0;
        unsigned int m = 1;
        for (int b = 0; b < 32; b++){
            if  (num & m) {
                bits[b] += (up ? 1 : -1);
            }
            if (bits[b] > 0){
                p |= m;
            }
            m <<= 1;
        }
        return p;
    }
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int i = 0, j = 0; 
        int bits[32];
        for (int b = 0; b < 32; b++) bits[b] = 0;
        unsigned int p =addBits(nums[0], bits);
        int min_length = nums.size();
        bool found = false;

        while (j < nums.size()){
            std::cout << p << std::endl;
            if (p >= k){
                found = true;
                if ((j-i+1) < min_length) min_length = j-i+1;
                if (i < j){
                    std::cout << "decrease" << std::endl;
                    p = addBits(nums[i], bits, false);
                    i++;
                } else return 1;
            }else{
                if (j < nums.size() -1 ){
                    j++;
                    std::cout << "increase" << std::endl;
                    p = addBits(nums[j], bits);
                } else break;
            }
        }
        if (found) return min_length;
        else return -1;
    }
};

int main (int argc, char *argv[]) {
    /*std::vector<int> nums = {1,2,32,21};*/
    /*int k = 55;*/
    std::vector<int> nums = {2,1,8};
    int k = 10;
    std::cout << Solution().minimumSubarrayLength(nums, k) << std::endl;
    
    return 0;
}
