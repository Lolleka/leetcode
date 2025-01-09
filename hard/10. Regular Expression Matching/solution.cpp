// https://leetcode.com/problems/regular-expression-matching
// hard
// #string, #dynamic-programming, #dp, #recursion

#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        if (s.size() > 0 && p.size() == 0) return false;
        assert(p.size() > 0);
        bool ans = false;
        if (p[0] == '.') {
            if (p.size() > 1 && p[1] == '*'){
                // trivial case
                if (s.size() == 0) return true;
                // either .* matches zero characters
                ans = isMatch(s, p.substr(2,p.size()-2));
                // or it matches at least one
                ans |= isMatch(s.substr(1,s.size()-1), p);
            }else{
                // match any character
                ans = isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1));
            }
        }else{
            if (p.size() > 1 && p[1] == '*'){
                // trivial case
                if (s.size() == 0) return true;
                // either .* matches at least one character
                ans = (s[0] == p[0] && isMatch(s.substr(1,s.size(), p)));
                // or it matches zero
                ans |= isMatch(s, p.substr(1,p.size()-1));
            } else {
                // it should match the character and the rest of the string
                ans = (s[0] == p[0] && isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1))));
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    std::string s = "aa";
    std::string p = "a";
    std::cout << std::boolalpha << Solution().isMatch(s,p) << std::endl;
    return 0;
}
