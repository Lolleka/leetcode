// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
// medium
// #array, #greedy, #sorting

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        // I need to find all overlapping baloons
        // for each set of overlapping baloons I'll need one arrow
        // For all isolated baloons I'll need a corresponding number
        // of arrows
        if (points.empty()) return 0;
        if (points.size() == 1) return 1;
        int arrows = 0;

        // sort the array by the second point
        std::sort(points.begin(),
                  points.end(),
                  [](std::vector<int> a, std::vector<int> b) { return a[1] < b[1];});

        // keep track of the second coordinate, starting with the first item
        // in the array, call this ref_x2
        int ref_x2 = points[0][1];
        // iterate the sorted array and accumulate points
        // until the first coordinate of the current point is > current_x2
        // when this condition is met, count 1 arrow, then update current_x2
        for (auto v: points){
            if (v[0] > ref_x2){
                arrows++;
                ref_x2 = v[1];
            }
        }
        arrows++;
        return arrows;
        
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    points = {{1,2},{3,4},{5,6},{7,8}};
    points = {{1,2},{2,3},{3,4},{4,5}};
    std::cout << Solution().findMinArrowShots(points) << std::endl;
    return 0;
}
