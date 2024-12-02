// https://leetcode.com/problems/non-overlapping-intervals/
// medium
// #array, #dynamic-programming, #dp, #greedy, #sorting

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int min_remove = 0;
        // sort intervals
        // by the ending point
        std::sort(intervals.begin(),
                  intervals.end(),
                  [](std::vector<int> a, std::vector<int> b) { return a[1] < b[1];});
        int i = 0; // start of overlapping cluster
        for (int k = 1; k < intervals.size(); k++){
            if (intervals[k][0] < intervals[i][1]){
                min_remove++;
            } else  i = k;
        }
        return min_remove;

    }
};

int main (int argc, char *argv[]) {
    std::vector<std::vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    std::cout << Solution().eraseOverlapIntervals(intervals) << std::endl;
    return 0;
}
