// https://leetcode.com/problems/move-pieces-to-obtain-a-string/
// medium
// #string, #two-pointers

#include <iostream>
#include <string>

class Solution {
public:
    bool canChange(std::string start, std::string target) {
        int n = start.size();
        int s = 0;
        int t = 0;
        while(true){
            while(start[s]=='_' && s < n) s++;
            while(target[t]=='_' && t < n) t++;
            /*std::cout << "s: " << s << " " << start[s] << " " << "t: " << t << " " << target[t] << std::endl;*/
            if (s == n && t == n) return true;
            if(start[s] != target[t]) return false;
            else if(start[s] == 'L' && s < t) return false;
            else if(start[s] == 'R' && s > t) return false;
            s++; t++;
        }
        return (s==n && t==n);
    }
};

int main (int argc, char *argv[]) {
    std::string start =  "_LL_R__R_";
    std::string target = "L__L___RR";
    /*start = "LLRR_"; target = "LL_RR";*/
    /*start = "_R"; target = "R_";*/
    std::cout << std::boolalpha << Solution().canChange(start, target) << std::endl;
    return 0;
}
