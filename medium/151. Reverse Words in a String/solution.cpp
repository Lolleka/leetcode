// https://leetcode.com/problems/reverse-words-in-a-string
// medium


#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class Solution{

public:
    std::string reverseWords(std::string s){
        std::stringstream in_ss(s);
        std::stack<std::string> s_stack;
        std::string word;
        while (in_ss >> word) s_stack.push(word);
        std::string out_s = s_stack.top(); s_stack.pop();
        while(!s_stack.empty()) {out_s += " " + s_stack.top(); s_stack.pop();}
        return out_s;
    }
};

int main(){
    std::string s("   a  b  c      d  hello  \t\t\t  world   ");
    std::cout << s << std::endl;
    std:: cout << Solution().reverseWords(s) << std::endl;
    return 0;
}
