// https://leetcode.com/problems/merge-strings-alternately
// easy
// #two-pointers, #string

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {

        std::string result = "";
        int l = std::max(word1.size(), word2.size());
        int i = 0;
        while(i < l){
            if (i < word1.size()) result += word1[i];
            if (i < word2.size()) result += word2[i];
            i++;
        }
        return result;
    }
};

int main (int argc, char *argv[]) {
    std::string word1 = "abcccc";
    std::string word2 = "pqr";
    std::cout << Solution().mergeAlternately(word1, word2) << std::endl;
    return 0;
}
