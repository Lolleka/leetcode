// https://leetcode.com/problems/edit-distance
// medium
// #string, #dynamic-programming, #dp

#include <iostream>
#include <string>

class Solution {
    std::unordered_map<std::string, int> dp;
public:
    void conditionalAdd(std::string word, int ops){
    }
    void applyOps(std::string word, std::set<char> allowedChars, int nops){
        // if an operation produces a word already in dp, do not perform.
        std::string modword = "";
        
        // elisions
        for (int i = 0; i < word.size(); ++i){
            // elision of character at i
            modword = word;
            conditionalAdd(modword.erase(i), ops);
        }
        for(char c: allowedChars){
            // insertions and replacements
            for (int i = 0; i < word.size(); ++i){
                // insertion before position i
                modwor = word;
                conditionalAdd(modword.insert(i,1,c), ops);
                // replacement of character at i
                modword = word;
                conditionalAdd(modword.replace(i, c), ops);
            }
            // insertion at the end of string
            modword = word;
            conditionalAdd(modword.append(c), ops);
        }
    }
    int minDistance(std::string word1, std::string word2) {
        // notes:
        // number of insertions or deletions
        // will equal difference in size
        // for replacements and insertions, only characters 
        // in word2 should be considered
        // worst case scenario is one where I substitute all characters
        // and insert / delete all necessary characters
        // so max operations = word2.size() + abs(word1.size()-word2.size())
        // we could brute force each operation sequentially
        // on each character, enforcing the known constraints
        std::string word = "";
        int nops = 0;
        while(nops < max_ops){
            nops++;
            if (dp.size() == 0) word = word1;
            else{
                for(auto p: dp){
                    word = p.first;
                    applyOps(word);
                }
            }
        }
    }
};

int main (int argc, char *argv[]) {
    std::string word1 = "horse";
    std::string word2 = "ros";
    return 0;
}
