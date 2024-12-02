// https://leetcode.com/problems/combination-sum-iii/
// medium
// #array, #backtracking

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(std::vector<std::vector<int> >& result, std::vector<int>& current, int k, int n){
        if (current.size() == k){
            int sum = 0;
            for (int i=0; i < k; i++){
                sum += current[i];
            }
            if (sum == n){
                result.push_back(current);
            }
        }

        for (int i=1; i <= 9; i++){
            if (std::find(current.begin(), current.end(), i) != current.end()){
                continue;
            }
            if (current.size() > 0 && i < current.back()){
                continue;
            }
            current.push_back(i);
            backtrack(result, current, k, n);
            current.pop_back();
        }
    }
    std::vector<std::vector<int> > combinationSum3(int k, int n) {
        std::vector<std::vector<int> > result;
        std::vector<int> current;
        backtrack(result, current, k, n);
        return result;
    }
};

int main( int argc, char **argv ) { 
    std::vector<std::vector<int> > result = Solution().combinationSum3(3, 9);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
