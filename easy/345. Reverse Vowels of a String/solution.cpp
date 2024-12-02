// https://leetcode.com/problems/reverse-vowels-of-a-string
// easy
// #two-pointers, #string

#include <iostream>
#include <string>

class Solution {
    bool isVowel(char c){
        return (
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
public:
    std::string reverseVowels(std::string s) {
        std::string result = "";
        int i = 0, j = s.size()-1;
        while(i < j){
            if (!isVowel(s[i])) i++;
            else if (!isVowel(s[j])) j--;
            else{
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
                i++; j--;
            }
        }
        return s; 
    }
};


int main (int argc, char *argv[]) {
    std::string s = "IceCreAm";
    std::cout << Solution().reverseVowels(s) << std::endl;
    return 0;
}
