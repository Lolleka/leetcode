// https://leetcode.com/problems/adding-spaces-to-a-string/
// medium
// #array, #two-pointers, #string, #simulation

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        std::string r(s.size()+spaces.size(), ' ');
        std::cout << s.size() << std::endl;
        std::cout << r.size() << std::endl;
        int s_start = 0;
        int r_start = 0;
        int width = 0;
        for(int i = 0; i < spaces.size(); ++i){
            width = spaces[i]-s_start;
            r.replace(r_start, width, s.substr(s_start, width));
            r_start += width+1;
            s_start = spaces[i];
        }
        width = s.size()-s_start;
        r.replace(r_start, width, s.substr(s_start,width));

        return r;
    }
};

int main (int argc, char *argv[]) {
    std::string s = "LeetcodeHelpsMeLearn";
    std::vector<int> spaces{8,13,15};
    std::cout << Solution().addSpaces(s, spaces) << std::endl;
    return 0;
}
