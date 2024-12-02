// https://leetcode.com/problems/removing-stars-from-a-string
// medium
// #string, #stack, #simulation, #queue

#include <iostream>
#include <string>
#include <deque>
#include <sstream>

class Solution{
    public:
    std::string removeStars(std::string s) {
        std::deque<char> sstack;
        std::ostringstream os;
        for (int i=0; i<s.size(); ++i){
            if (s[i] == '*' && !sstack.empty())
                sstack.pop_back();
            else
                sstack.push_back(s[i]);
        }
        while(!sstack.empty()){
            os << sstack.front();
            sstack.pop_front();
        }
        return os.str();
    }
};

int main (int argc, char *argv[]) {
    std::string s = "leet**cod*e";
    std::cout << Solution().removeStars(s) << std::endl;
    return 0;
}
