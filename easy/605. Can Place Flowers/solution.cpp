// https://leetcode.com/problems/can-place-flowers/
// easy

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         int f = n;

        if (n == 0) return true;
        if (flowerbed.size() == 1)
            return (n==0 || (n==1 && !flowerbed[0]));
        if (!flowerbed[0] && !flowerbed[1]){
            flowerbed[0] = 1;
            f--;
        }
        int i = 1;
        while(f > 0 && i < flowerbed.size()-1){
             if (!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1]){
                    flowerbed[i] = 1;
                    f--;
                }
            
            i++;
        }
        if ( !flowerbed[i] && !flowerbed[i-1]){
            flowerbed[i] = 1;
            f--;
        }
        return f <= 0;
    }
};

int main(){
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    /* vector<int> nums = {20,100,10,12,5,13}; */
    cout << boolalpha << Solution().canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}
