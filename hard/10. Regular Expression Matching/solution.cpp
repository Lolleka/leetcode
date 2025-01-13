// https://leetcode.com/problems/regular-expression-matching
// hard
// #string, #dynamic-programming, #dp, #recursion

// TODO: solution is not optimal, implement dp solution

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        if (s.size() > 0 && p.size() == 0) return false;
        assert(p.size() > 0);
        bool ans = false;
        /*std::cout << s << std::endl << p << std::endl << "---\n";*/
        if (p[0] == '.') {
            if (p.size() > 1 && p[1] == '*'){
                // either .* matches zero characters
                ans = isMatch(s, p.substr(2,p.size()-2));
                // or it matches at least one
                ans |= (s.size() > 0 && isMatch(s.substr(1,s.size()-1), p));
            }else{
                // match any character
                ans = (s.size() > 0 && isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1)));
            }
        }else{
            if (p.size() > 1 && p[1] == '*'){
                // either _* matches at least one character
                // while(s[0]==p[0])s = s.substr(1,s.size()-1);
                ans = (s.size() > 0 && s[0]==p[0] && isMatch(s.substr(1,s.size()-1), p));
                // or it matches zero
                ans |= isMatch(s, p.substr(2,p.size()-2));
            } else {
                // it should match the character and the rest of the string
                ans = (s[0] == p[0] && s.size() > 0 && isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1)));
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[]) {
    std::string s = "aaaaaaaaaaaaaaaaaaa";
    std::string p = "a*a*a*a*a*a*a*a*a*a";
    s="ab";
    p=".*";
    std::cout << std::boolalpha << Solution().isMatch(s,p) << std::endl;
    return 0;
}
