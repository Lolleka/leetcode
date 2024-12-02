// https://leetcode.com/problems/string-compression/
// medium
// #two-pointers, #string

#include <iostream>
#include <vector>
#include <string>

class Solution{
    int add_entry(std::vector<char>::iterator& it1, char c, int count){
        int length = 0;
        if(count==1){
            *it1 = c;
            it1++;
            length++;
        }else if (count > 9){ 
            *it1 = c;
            it1++;
            length ++;
            std::string num = std::to_string(count);
            for(int i=0; i<num.size(); ++i){
                *it1 = num[i];
                it1++;
                length ++;
            }
            count = 0;
        }else{
            *it1 = c;
            it1++;
            *it1 = '0' + count;
            it1++;
            length +=2;
        }
        return length;
    }
public:
    int compress(std::vector<char>& chars) {
        std::vector<char>::iterator it1, it2;
        int length = 0;
        it1 = chars.begin();
        it2 = chars.begin();
        char current = *it2;
        int count = 1;
        it2++;
        while(it2 != chars.end()){
            if (*it2 != current){
                length += add_entry(it1, current, count);
                current = *it2;
                count = 1;
            } else count++;
            it2++;
        }
        length += add_entry(it1, current, count);
        return length;
    }
};

int main (int argc, char *argv[]) {
    std::vector<char> chars{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int l = Solution().compress(chars);
    std::cout << "len = " << l << std::endl;
    std::string s = "";
    for (int i =0; i<l; ++i) s+=chars[i];
    std::cout << "chars = " << s << std::endl;
    
    return 0;
}
