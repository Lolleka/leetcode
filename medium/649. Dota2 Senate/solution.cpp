// https://leetcode.com/problems/dota2-senate
// medium
// #string, #greedy, #queue

#include <iostream>
#include <string>
#include <deque>
#include <sstream>

class Solution{
    char checkVictory(const std::string& senate){
        int D = 0, R = 0;
        for (int i=0; i<senate.size(); ++i){
            if(senate[i] == 'D') {if (R == 0) D++; else return 'X';}
            if(senate[i] == 'R') {if (D == 0) R++; else return 'X';}
        }
        return D > R ? 'D' : 'R';
    }
    
    public:
    std::string predictPartyVictory(std::string senate) {
        int Dban = 0;
        int Rban = 0;
        while(checkVictory(senate) == 'X'){
            // start round
            for (int i=0; i<senate.size(); ++i){
                if(senate[i] == 'R'){
                    if (Rban){ senate[i] = 'X'; Rban--;}
                    else Dban++;
                }
                else if(senate[i] == 'D'){
                    if (Dban){ senate[i] = 'X'; Dban--;}
                    else Rban++;
                }
            }
            std::cout << senate << " (" << checkVictory(senate) << ")" << std::endl;
        }
        return checkVictory(senate) == 'D' ? "Dire" : "Radiant";
    }
};

int main (int argc, char *argv[]) {
    std::string s = "RDDDD";
    std::cout << Solution().predictPartyVictory(s) << std::endl;
    return 0;
}
