// https://leetcode.com/problems/longest-common-subsequence
// medium
// #string, #dynamic-programming, #dp

#include <iostream>
#include <string>

class Solution {

public:
    int solve(std::string* s, std::string* l){
        int M = s->size();
        int N = l->size();
        int* dp = new int[M*N];
        auto I = [N](int i, int j){return i*N+j;};
        
        int s_len = 0;
        for (int i = 0; i < s->size(); ++i){
            for (int j = 0; j < l->size(); ++j){
                if ((*s)[i] == (*l)[j]){
                    if (i > 0 && j > 0)
                        dp[I(i,j)] = dp[I(i-1,j-1)] + 1;
                    else if( i > 0 )
                        dp[I(i,0)] = dp[I(i-1,0)] + 1;
                    else if( j > 0 )
                        dp[I(0,j)] = dp[I(0,j-1)] + 1;
                    else
                        dp[I(0,0)] = 1;
                }else{
                    if (i > 0 && j > 0)
                        dp[I(i,j)] = std::max(dp[I(i-1,j)], dp[I(i,j-1)]);
                    else if( i > 0 )
                        dp[I(i,0)] = dp[I(i-1,j)];
                    else if( j > 0 )
                        dp[I(0,j)] = dp[I(i,j-1)];
                    else
                        dp[I(0,0)] = 0;
                }
                if (dp[I(i,j)] > s_len) s_len = dp[I(i,j)];
            }
        }
        return s_len;
    }
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        return solve(&text1, &text2);
    }
};

int main(){
    /* std::string text1 = "abc"; */
    /* std::string text2 = "def"; */
    std::string text1 = "qqqzqzqzqzqqqqzqqqqqqzqqqqqqzqqzqqqqqzzqzzqqqqzqqzqqqqzzqqzzzqqqzzqzzzzqzqqqqzzqzqqqqqqqqzzqzzzzqzqzqqqqqzqzqzzqqqzqqzzqqqzqqzqqzqzqzqqqqqzqzzzzqqqqqqzzzqqzqzqqzqqqqzqqzqzzzqqzqzzzzqqqqzzqqqqqqqqqqzqqqzqzqzqqzqqqzqqqzzqzqqqqqzqzqqqqzqqqqqqqzzqzqzqqqzqqzzqzqqqzqqqzzqqqqqzqzqzqqqqqqqqqqzqqzqzqqqqqqqzqzzqqqqqqzqqzqqqqzqqqzqqqqqzqqqqqzqqqzqzqzqqqzzqqqqzqqzzqqqzzqqqqzzzqqqqqqzqqzqqzqqqzzqqqqzzqqzzqzqzzqqqzqqqqzzqzqzzzzqqqzqzqzzqqzzqqqqqqzqqqqqqqqqzzqzqqqzqzqqqqqqqqqzqzqqzqqqzzqqzzqqqqqqqqqqqqzzqqqzqzqzqqqqqzqqqqzzqqzqqqzqzqzqqqzzqqqqqqqqqzqzqzqqqzzzqqqzzqqqzqzzqzzzqqzqqqqzqzqqzqzqqqqqqqqzzqqqzqzzqqqqzzqzzqzqqqqqqqzqqqzqqqqqqqqzqqqqzqqqzqzqqzqqzzzzqqzzqqzqqzqqqzqqqqqqqqqqqzzqzzqqqzqqqzqzzqqzqqqzzzqzqqqqqqqqqqqzzqqzqqqqzzqqqzqqzqqqqqqzqqqqqzqqqqqzzqqqzqqqqzzzqqqqqqzzzzqqqzqzqzqqqqzqqzzzzqqqqzqqqzzzqqzqzqzqzzqzzzqqzqqqzqqqzqzqqqzqqqqqzqqqzzqqqqzqqqzqzzqzzqqzqzzqqqqzqqqqqzqqqqqqqqqqzqqzzqqzzqqqqqzqqzzzzqqqqqqqqzqzzqqzzqzqqqqqqqzqqzqqqqqzqqqzqqzqzqzzqqzqzqqqzqzzqqzqqqqqqzqqqzzzqzqqqqqqqzqqqzzzqq";
    std::string text2 = "qzqqqqqzzqqqqzqqzqzqqqqqqqzqqqzqqzzqqqqzzzzqqqqzqqqqzzqqzqqqqqzqzqzqzqzqqqzqzqqqqqqzzqqqqqqzqzzqqqqzqqqzqzzqqzqzqqzqzqqqqzqqzzzzqqzzqzqqzqzqqqqqzqzqzzqqzqzqqqqzqzzqqqqzzqzqqqzqqzqqqzqzqzqqqzzqqqqzqqqzqqqzqqzqqzqqzqqqqzqqqzzqzzqzzzqqqqqzqzqqqqqqzqqqqzqqqqqzzqqqqqzqzzqqqzqqqqqqqzzzzqqzzqqqzzqzqzqqqqqqzzzqzqqqzzzzzqzqqqqzqqqzqqqqqqqqzzqqqqzqqqqqqqzqqzzzqqqqzqqqqzzqzzqqzqqzqqzqzqzqzqqqqqqqqzzzqqqqzqzqqqzzqqqqzzqqqzqqqqqqzzzqqzqzqzqqqzqqqzqqqqqzqqzzqzqqqqqzqqqqqqqzqqqzqqqqqzqzqqqqqqzqqqqqzqqqzqqqzzqzzqqqqqqqzqqzqqzzzqqqzqqqqqqqqqzzzqzqqqqqqzqzqzqqqqqzqqqqqqqqzzqqqzqzqzzqqqqqqzqqqzqqqzqzqqqqzqqzqqqzqzzqqzzqzqqzqqqqzqqzqqqqzqqzzqqqqqqqzzqqqqzqzzzqzzzzqzqqqqqqzqzqqzqzqqzzzqzqqzqqzqqzzqzqqqzqqqqzqqqqqqqzqzqzqzqzzqqzqqqqzqqzqqqqqzqzqqqqzqzzqqzqzzqzqqqqzzqqqqqzqqzqqqqqqqqqqqqzqqzqqqzqqqqqqqqzqqzzqqqqqzzqqzqqqqzqzqzqzqqqqqqqqzzqqqzqqqzzqqqzzqzqqqzqqqzqqqqqqqzqqzqzqqqzzqzqqqqzqzqqzzzzqqqqzqzqqzqqqqzqzzqqzzzqzqzzzzqqzqzqqqqqzzqqqzzqqzqzzqqzzqqqqqqqzzzzqqqqqqqqqqqzqqqqqzzqqzzqzqqzzqqqzzqqqzqqzzqqqqzq";
    /* std::string text1 = "mhunuzqrkzsnidwbun"; */
    /* std::string text2=  "szulspmhwpazoxijwbq"; */
    std::cout << Solution().longestCommonSubsequence(text1, text2) << std::endl;

    return 0;

}
