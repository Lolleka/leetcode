// https://leetcode.com/problems/determine-if-two-strings-are-close
// medium
// #hash-table, #string, #sorting, #counting

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        // looks like the statement is equivalent to:
        // 1) sorting the two strings in lexographic order
        // 2) checking that both strings have the same charactes
        // 3) checking that the sequence of counts for the characters
        //    is the same

        // if size does not match, strings are not close
        if (word1.size() != word2.size()) return false;
        int length = word1.size();

        // sort strings
        std::sort(word1.begin(), word1.end());
        std::sort(word2.begin(), word2.end());

        // perform 2) and 3) in one for loop
        std::vector<int> num_chars1;
        std::vector<int> num_chars2;
        char current = word1[0];

        int i1 = 0, i2 = 0;
        int w1 = 0, w2 = 0;
        while(i1 < length){
            if (word1[i1] != word2[i2]) return false;
            current = word1[i1];
            while(i1 < length && word1[i1] == current){ i1++; w1++;}
            while(i2 < length && word2[i2] == current){ i2++; w2++;}
            num_chars1.push_back(w1); w1 = 0;
            num_chars2.push_back(w2); w2 = 0;
        }

        // sort num_chars vectors
        std::sort(num_chars1.begin(), num_chars1.end());
        std::sort(num_chars2.begin(), num_chars2.end());

        // num_chars arrays should be the same
        for(int i = 0; i < num_chars1.size(); ++i)
            if (num_chars1[i] != num_chars2[i]) return false;

        return true;
    }
};

int main (int argc, char *argv[]) {
    std::string s1 = "aaab";
    std::string s2 = "bbaa";
    std::cout << std::boolalpha << Solution().closeStrings(s1, s2) << std::endl;
    return 0;
}
