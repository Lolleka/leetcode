// https://leetcode.com/problems/decode-string
// medium 
#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

class Solution {
    int findMatchingBracket(std::string& s, int pos = 0){
        int n = 0;
        while(pos < s.size()){
            if (s[pos] == ']'){
                if(n == 0) break;
                else n--;
            }
            else if(s[pos] == '[') n++;
            pos++;
        }
        return pos;
    }
public:
    std::string decodeString(std::string s) {
        int n = 0;
        int k = 0;
        std::size_t f = 0;
        std::size_t g = std::string::npos;
        std::string outer_str;
        // capture nondigit sequence
        do{
            while(!isdigit(s[k]) && k < s.size()) k++;
            outer_str += s.substr(f, k-f);
            if (k == s.size()) break;

            f = s.find('[', k);
            if ( f != std::string::npos ) {
                // convert reps number
                n = std::stoi(s.substr(k,f-k));
                // expand inner string
                g = findMatchingBracket(s,f+1);
                std::string inner_s = decodeString(s.substr(f+1, g-f-1));
                // apply reps
                for (int i = 0; i < n; i++) outer_str += inner_s;
                f = g+1;
                k = f;
            }else std::cout << "not found" << std::endl;
        }while(f != std::string::npos);
        return outer_str;
    }
};


int main (int argc, char *argv[]) {
    std::string s = "2[abc]3[cd]ef";
    s ="3[a]2[bc]";
    std::cout << Solution().decodeString(s) << std::endl;
    return 0;
}
