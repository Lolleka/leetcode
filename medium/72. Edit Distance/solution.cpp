// https://leetcode.com/problems/edit-distance
// medium
// #string, #dynamic-programming, #dp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        // notes:
        // this should be an implementation of the Levenshtein distance
        int n = word1.size();
        int m = word2.size();
        std::vector<std::vector<int>> lev(n+1, std::vector<int>(m+1,0));
        // source prefixes can be transformed into empty string by
        // dropping all characters
        for(int j = 1; j < n; j++) lev[j][0] = j;
        // target prefixes can be reached from empty source prefix by
        // inserting every character
        for(int i = 1; i < m; i++) lev[0][i] = i;
        int subCost = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                subCost = static_cast<int>(word1[i-1] != word2[j-1]);
                lev[i][j] = std::min(lev[i-1][j] + 1,  // deletion
                                     lev[i][j-1] + 1); // insertion
                lev[i][j] = std::min(lev[i][j], lev[i-1][j-1] + subCost); // substitution
                /*std::cout << lev[i][j] << std::endl;*/
            }
        }

        return lev[n-1][m-1];
    }
};

int main (int argc, char *argv[]) {
    std::string word1 = "horse";
    std::string word2 = "ros";
    /*word1 = "code";*/
    /*word2 = "leetcode";*/
    std::cout << Solution().minDistance(word1, word2) << std::endl;
    return 0;
}
