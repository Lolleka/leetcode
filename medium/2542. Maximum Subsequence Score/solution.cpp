// https://leetcode.com/problems/maximum-subsequence-score
// medium
// #array, #greedy, #sorting, #heap

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    typedef std::pair<int,int> Pair;

    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<Pair> pairs;
    // join two arrays
    for(int i = 0; i < nums1.size(); ++i)
        pairs.push_back(std::make_pair(nums1[i],nums2[i]));
    // sort pairs in descending order of pair.second
    std::sort(pairs.begin(),
              pairs.end(),
              [](Pair a, Pair b) { return a.second >= b.second;});
    for (Pair p: pairs)
        std::cout << p.first << ", " << p.second << std::endl;


    // set up a mean priority queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    long long sum = 0;

    for(int i = 0; i < k; ++i){
        sum += pairs[i].first;
        heap.push(pairs[i].first);
    }

    long long max_score = sum * pairs[k-1].second;

    // iterate on sorted array
    for (int i = k; i < pairs.size(); ++i){
        // at each iteration, pop the minimum element from the heap
        sum -= heap.top(); heap.pop();
        // add current element to heap
        heap.push(pairs[i].first);
        // update sum
        sum += pairs[i].first;
        if(sum*pairs[i].second > max_score)
            max_score = sum*pairs[i].second;
    }
    return max_score;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> nums1, nums2;
    nums1 = {2,1,14,12};
    nums2 = {11,7,13,6};
    int k = 3;
    std::cout << Solution().maxScore(nums1, nums2, k) << std::endl;
    return 0;
}
