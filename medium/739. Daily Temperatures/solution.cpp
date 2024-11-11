// https://leetcode.com/problems/daily-temperatures
// medium

#include <iostream>
#include <vector>
#include <stack>
#include <utility>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> answer(temperatures.size(), 0);
        std::stack<int> st;
        /*for(int i=answer.size()-1; i >= 0; --i){*/
        for(int i=0; i < answer.size(); ++i){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int j = st.top();
                st.pop();
                answer[j] = i-j;
            }
            st.push(i);
            /*while(i < temperatures.size() && temperatures[j] <= temperatures[i] ){*/
            /*    answer[i]++; j++;*/
            /*}*/
        }
        return answer;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> temps = {73,74,75,71,69,72,76,73};
    for (auto v: Solution().dailyTemperatures(temps)) std::cout << v << " ";
    std::cout << std::endl;
    return 0;
}
