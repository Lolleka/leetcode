// https://leetcode.com/problems/counting-words-with-a-given-prefix
// medium
// #array, #string, #string-matching

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) {
        int count = 0;
        for (std::string& w: words){
            if (w.substr(0, pref.size()) == pref) count++;
        }        
        return count;
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::string> words ={"pay","attention","practice","attend"};
    std::string pref = "at";
    std::cout << Solution().prefixCount(words, pref) << std::endl;
    return 0;
}
