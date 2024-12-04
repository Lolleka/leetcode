// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments
// medium
// #two-pointers, #string

#include <iostream>
#include <string>

class Solution {
public:
    bool canMakeSubsequence(std::string str1, std::string str2) {
        if (str2.size() > str1.size()) return false;
        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()){
            char cycled = str1[i] == 'z' ? 'a' : str1[i] + 1;
            if(str1[i]==str2[j] || cycled == str2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j == str2.size();
    }
};

int main (int argc, char *argv[]) {
    std::string str1 = "abc";
    std::string str2 = "ad";
    str1 = "a";
    str2 = "d";
    std::cout << std::boolalpha << Solution().canMakeSubsequence(str1,str2) << std::endl;
    return 0;
}
