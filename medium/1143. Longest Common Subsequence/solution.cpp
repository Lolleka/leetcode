// https://leetcode.com/problems/longest-common-subsequence
// medium
// #string, #dynamic-programming, #dp

#include <iostream>
#include <string>

class Solution {
public:
    int longestCommonSubsequence(std::string& s, std::string& l) {
        int M = s.size();
        int N = l.size();
        int* dp = new int[M*N];
        for (int i = 0; i < M*N; ++i) dp[i] = 0;
        // this problem is similar to te levenshtein distance
        auto I = [N](int i, int j){return i*N+j;};
        // initialize the trivial case where one of the strings is just one
        // character long
        
        dp[I(0,0)] = static_cast<int>(s[0] == l[0]);
        for (int i = 1; i < M; ++i)
            dp[I(i,0)] = std::max(dp[I(i-1,0)],static_cast<int>(s[i] == l[0]));
        for (int j = 1; j < N; ++j)
            dp[I(0,j)] = std::max(dp[I(0,j-1)],static_cast<int>(s[0] == l[j]));
       
        int s_len = std::max(dp[I(0,N-1)],dp[I(M-1,0)]);

        for (int i = 1; i < M; ++i){
            for (int j = 1; j < N; ++j){
                if (s[i] == l[j]){ // if the characters at the two positions are equal
                    // if i > 0 and j > 0, find the common length at i-1, j-1 and increment
                    dp[I(i,j)] = dp[I(i-1,j-1)] + 1;
                }else{ // if the characters are not equal
                    // if i > 0 and j > 0, the max common lenght is either the
                    // one found when we elide the sources char and keep the dest
                    // char, and then we need to check i-1,j, or is found by eliding
                    // the character of the dest and keeping the one in the source,
                    // i.e. we check i, j-1
                    dp[I(i,j)] = std::max(dp[I(i-1,j)], dp[I(i,j-1)]);
                }
                if (dp[I(i,j)] > s_len) s_len = dp[I(i,j)];
            }
        }
        return s_len;
    }
};

int main(){
    std::string text1 = "abcde"; 
    std::string text2 = "ace"; 
    /*text1 = "qqqzqzqzqzqqqqzqqqqqqzqqqqqqzqqzqqqqqzzqzzqqqqzqqzqqqqzzqqzzzqqqzzqzzzzqzqqqqzzqzqqqqqqqqzzqzzzzqzqzqqqqqzqzqzzqqqzqqzzqqqzqqzqqzqzqzqqqqqzqzzzzqqqqqqzzzqqzqzqqzqqqqzqqzqzzzqqzqzzzzqqqqzzqqqqqqqqqqzqqqzqzqzqqzqqqzqqqzzqzqqqqqzqzqqqqzqqqqqqqzzqzqzqqqzqqzzqzqqqzqqqzzqqqqqzqzqzqqqqqqqqqqzqqzqzqqqqqqqzqzzqqqqqqzqqzqqqqzqqqzqqqqqzqqqqqzqqqzqzqzqqqzzqqqqzqqzzqqqzzqqqqzzzqqqqqqzqqzqqzqqqzzqqqqzzqqzzqzqzzqqqzqqqqzzqzqzzzzqqqzqzqzzqqzzqqqqqqzqqqqqqqqqzzqzqqqzqzqqqqqqqqqzqzqqzqqqzzqqzzqqqqqqqqqqqqzzqqqzqzqzqqqqqzqqqqzzqqzqqqzqzqzqqqzzqqqqqqqqqzqzqzqqqzzzqqqzzqqqzqzzqzzzqqzqqqqzqzqqzqzqqqqqqqqzzqqqzqzzqqqqzzqzzqzqqqqqqqzqqqzqqqqqqqqzqqqqzqqqzqzqqzqqzzzzqqzzqqzqqzqqqzqqqqqqqqqqqzzqzzqqqzqqqzqzzqqzqqqzzzqzqqqqqqqqqqqzzqqzqqqqzzqqqzqqzqqqqqqzqqqqqzqqqqqzzqqqzqqqqzzzqqqqqqzzzzqqqzqzqzqqqqzqqzzzzqqqqzqqqzzzqqzqzqzqzzqzzzqqzqqqzqqqzqzqqqzqqqqqzqqqzzqqqqzqqqzqzzqzzqqzqzzqqqqzqqqqqzqqqqqqqqqqzqqzzqqzzqqqqqzqqzzzzqqqqqqqqzqzzqqzzqzqqqqqqqzqqzqqqqqzqqqzqqzqzqzzqqzqzqqqzqzzqqzqqqqqqzqqqzzzqzqqqqqqqzqqqzzzqq";*/
    /*text2 = "qzqqqqqzzqqqqzqqzqzqqqqqqqzqqqzqqzzqqqqzzzzqqqqzqqqqzzqqzqqqqqzqzqzqzqzqqqzqzqqqqqqzzqqqqqqzqzzqqqqzqqqzqzzqqzqzqqzqzqqqqzqqzzzzqqzzqzqqzqzqqqqqzqzqzzqqzqzqqqqzqzzqqqqzzqzqqqzqqzqqqzqzqzqqqzzqqqqzqqqzqqqzqqzqqzqqzqqqqzqqqzzqzzqzzzqqqqqzqzqqqqqqzqqqqzqqqqqzzqqqqqzqzzqqqzqqqqqqqzzzzqqzzqqqzzqzqzqqqqqqzzzqzqqqzzzzzqzqqqqzqqqzqqqqqqqqzzqqqqzqqqqqqqzqqzzzqqqqzqqqqzzqzzqqzqqzqqzqzqzqzqqqqqqqqzzzqqqqzqzqqqzzqqqqzzqqqzqqqqqqzzzqqzqzqzqqqzqqqzqqqqqzqqzzqzqqqqqzqqqqqqqzqqqzqqqqqzqzqqqqqqzqqqqqzqqqzqqqzzqzzqqqqqqqzqqzqqzzzqqqzqqqqqqqqqzzzqzqqqqqqzqzqzqqqqqzqqqqqqqqzzqqqzqzqzzqqqqqqzqqqzqqqzqzqqqqzqqzqqqzqzzqqzzqzqqzqqqqzqqzqqqqzqqzzqqqqqqqzzqqqqzqzzzqzzzzqzqqqqqqzqzqqzqzqqzzzqzqqzqqzqqzzqzqqqzqqqqzqqqqqqqzqzqzqzqzzqqzqqqqzqqzqqqqqzqzqqqqzqzzqqzqzzqzqqqqzzqqqqqzqqzqqqqqqqqqqqqzqqzqqqzqqqqqqqqzqqzzqqqqqzzqqzqqqqzqzqzqzqqqqqqqqzzqqqzqqqzzqqqzzqzqqqzqqqzqqqqqqqzqqzqzqqqzzqzqqqqzqzqqzzzzqqqqzqzqqzqqqqzqzzqqzzzqzqzzzzqqzqzqqqqqzzqqqzzqqzqzzqqzzqqqqqqqzzzzqqqqqqqqqqqzqqqqqzzqqzzqzqqzzqqqzzqqqzqqzzqqqqzq";*/
    /* std::string text1 = "mhunuzqrkzsnidwbun"; */
    /* std::string text2=  "szulspmhwpazoxijwbq"; */
    std::cout << Solution().longestCommonSubsequence(text1, text2) << std::endl;

    return 0;

}
