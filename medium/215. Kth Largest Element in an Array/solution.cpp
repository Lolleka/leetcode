// https://leetcode.com/problems/kth-largest-element-in-an-array
// medium

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int>  min_pq;
        for (int n: nums) min_pq.push(n);
        for (int i=0; i<k-1; ++i) {
            int prev=min_pq.top();
            min_pq.pop();
        }
        return min_pq.top();
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    std::cout << Solution().findKthLargest(nums, k) << std::endl;
    return 0;
}
