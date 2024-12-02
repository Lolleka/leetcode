// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
// easy
// #two-pointers, #string, #string-matching

#include <iostream>
#include <string>

class Solution {
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord) {
        int i = 0, j =0, c=1;
        int result = -1;
        while(j < sentence.size()){
            if (sentence[j] == searchWord[i]){
                if (i == searchWord.size()-1){
                    result = c; break;
                }else{
                    //advance both pointers
                    j++;
                    i++;
                }
            }else{
                i = 0;
                // advance j to next space
                while(sentence[j] != ' ' && j < sentence.size()) j++;
                // increment word counter
                // set j to start of word
                if(j < sentence.size()){j++; c++;} else break;
            }
        }
        return result;
        
    }
};

int main (int argc, char *argv[]) {
    std::string sentence = "i love eating burger"; 
    std::string searchWord = "burg"; 
    sentence = "i am tired";
    searchWord = "you";
    sentence = "this problem is an easy problem";
    searchWord = "pro";
    std::cout << Solution().isPrefixOfWord(sentence, searchWord) << std::endl;
    return 0;
}
