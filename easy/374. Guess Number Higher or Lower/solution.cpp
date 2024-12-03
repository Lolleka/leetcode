// https://leetcode.com/problems/guess-number-higher-or-lower
// easy
// #binary-search, #interactive
#include <iostream>

class Solution {
    int secret = 0;
    int guess(int num){
        if (num == secret) return 0;
        else if( num > secret) return -1;
        else return 1;
    }
public:
    int guessNumber(int n) {
        secret = n/4;
        std::cout << "secret: " << secret << std::endl;
        int res = 0;
        int a = INT_MAX;
        int b = 0;
        while(true){
        /*std::cout << "a: " << a << ", b: " << b << std::endl;*/
            res = guess((a+b)/2);
            if (res==0) return (a+b)/2;
            else if(res == -1) b = (a+b)/2;
            else if(res == 1) a = (a+b)/2;
        }
        
    }
};

int main (int argc, char *argv[]) {
    std::cout << Solution().guessNumber(10) << std::endl;
    return 0;
}
