// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
// easy
// #string, #sliding-window

#include <iostream>
#include <string>
#include <cassert>

class Solution {
    int isVowel(char c){
        return static_cast<int>(
        c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' || 
        c == 'u' ||
        c == 'A' ||
        c == 'E' ||
        c == 'I' ||
        c == 'O' || 
        c == 'U');
    }

    int countVowels(const std::string& s){
        int count = 0;
        for(char c: s) count += static_cast<int>(isVowel(c));
        return count;
    }
public:
    int maxVowels(std::string s, int k) {
        // set the initial count, we'll update in the main loop
        int count = countVowels(s.substr(0,k));
        int max_count = count;
        assert(k <= s.size());
        // use a sliding window to update count
        for(int i = 1; i <= s.size()-k; i++){
            count += isVowel(s[i+k-1]) - isVowel(s[i-1]);
            if (count > max_count) max_count = count;
        }
        return max_count;
    }
};

int main (int argc, char *argv[]) {
    std::string s = "tryhard";
    int k = 4;
    std::cout << Solution().maxVowels(s, k) << std::endl;
    return 0;
}
