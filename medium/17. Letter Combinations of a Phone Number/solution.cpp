// https://leetcode.com/problems/letter-combinations-of-a-phone-number
// medium

#include <iostream>
#include <string>
#include <vector>
#include <map>


class Solution {
    std::map<char, std::string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    void backtrack(std::vector<std::string>& result, std::string& current, std::string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        char digit = digits[index];
        std::string letters = phone[digit];
        for (int i = 0; i < letters.size(); i++) {
            current.push_back(letters[i]);
            backtrack(result, current, digits, index + 1);
            current.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }
        std::string current;
        backtrack(result, current, digits, 0);
        return result;
        
    }
};

int main (int argc, char *argv[]) {
    std::string digits = "23";
    std::vector<std::string> result = Solution().letterCombinations(digits);
    for(auto& s : result) {
        std::cout << s << std::endl;
    }
    
    return 0;
}
