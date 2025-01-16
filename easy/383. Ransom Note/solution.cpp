// https://leetcode.com/problems/ransom-note
// medium
// #hash-table, #string, #counting, #sorting

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::sort(ransomNote.begin(), ransomNote.end());
        std::sort(magazine.begin(), magazine.end());
        int i = 0; int j = 0;
        bool retval = true;
        while(true){
            if (i >= ransomNote.size()) break;
            if(j >= magazine.size()) { retval = false; break;}
            if(ransomNote[i] == magazine[j]){
                i++;
                j++;
            } else j++;
        }
        return retval;
    }
};

int main (int argc, char *argv[]) {
    std::string ransomNote = "aab";
    std::string magazine = "baa";
    std::cout << std::boolalpha << Solution().canConstruct(ransomNote, magazine) << std::endl;
    return 0;
}
