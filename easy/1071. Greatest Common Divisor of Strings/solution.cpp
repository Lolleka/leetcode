// https://leetcode.com/problems/greatest-common-divisor-of-strings
// easy
// #math, #string

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool checkMultiple(std::string target, std::string sub){
        if(target.size() == 0 || sub.size() == 0) return false;
        if(target.size() < sub.size() || target.size() % sub.size() != 0) return false;
        while(target.size()){
            if (target.substr(0,sub.size()) != sub) return false;
            target = target.substr(sub.size(), target.size()-sub.size());
        }
        return true;
    }
    std::string gcdOfStrings(std::string str1, std::string str2) {
        std::string target = str1.size() > str2.size() ? str1 : str2;
        std::string sub = str1.size() > str2.size() ? str2 : str1;
        std::string result = "";
        std::cout << target << std::endl;
        std::cout << sub << std::endl;
        for (int i = 1; i<=sub.size(); ++i){
            if(checkMultiple(target, sub.substr(0,i)) && 
               checkMultiple(sub, sub.substr(0,i))){
                result = sub.substr(0,i); 
            }
        }
        return result;
    }
};

int main (int argc, char *argv[]) {
    std::string word1 ="TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    std::string word2 ="TAUXXTAUXXTAUXXTAUXXTAUXX";
    word1 = "ABABABAB";
    word2 = "ABAB";
    std::cout << Solution().gcdOfStrings(word1, word2) << std::endl;
    return 0;
}
