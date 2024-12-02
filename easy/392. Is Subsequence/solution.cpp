// https://leetcode.com/problems/is-subsequence
// easy
// #two-pointer, #string, #dynamic-programming, #dp

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0; int j = 0;
        while(i < s.size() && j < t.size()){
            if (s[i] == t[j]) i++;
            j++;
        }
        return i==s.size();
    }
};

int main (int argc, char *argv[]) {
    std::string s = "abc";
    std::string t = "ahbgdd";
    std::cout << std::boolalpha << Solution().isSubsequence(s,t) << std::endl;
    return 0;
}
