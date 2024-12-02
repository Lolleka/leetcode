// https://leetcode.com/problems/increasing-triplet-subsequence/
// medium
// #array, #greedy

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;


template<typename T>
vector<size_t> sort_indices(const vector<T> &v, bool reverse = false){
    // initialize original index locations
    vector<size_t> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);
    
    std::stable_sort(idx.begin(), idx.end(),
            [&v, reverse](size_t i1, size_t i2) { return reverse ? v[i1] > v[i2] : v[i1] < v[i2]; });
    return idx;
}

class Solution {

public:
    bool increasingTriplet(const vector<int>& nums) {
        vector<pair<int, int>> seqs;

        // initialize seqs with one sequence starting at i=0
        seqs.push_back(make_pair(0,-1));

        for (int i = 1; i < nums.size(); ++i){
            int c = nums[i];
            int min_a = nums[seqs[0].first];
            int s_i = 0;
            for (int j = 0; j < seqs.size(); ++j){
                pair<int, int>* s = &seqs[j];
                cout << s_i++ << ": <" << s->first << "," << s->second << ">" << endl;
                int a = nums[s->first];
                // keep track of the minimum first element in the set of seqs
                if (a < min_a) min_a = a;
                if (s->second > 0){
                    // if second element is already set, check for termination
                    int b = nums[s->second];
                    if (c > b) return true; // return true if c > b
                    else if (c > a && c < b ) s->second = i; // update second if a < c < b
                }else{
                    // if second is not set and c > a, set it
                    if (c > a) s->second = i;
                }
            }
            cout << "min_a = " << min_a << endl;
            if (c < min_a) { 
                // start a new sequence if we encountered a new minimum
                seqs.push_back(make_pair(i, -1));
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums = {2,1,5,0,4,6};
    /* vector<int> nums = {20,100,10,12,5,13}; */
    cout << boolalpha << Solution().increasingTriplet(nums) << endl;
    return 0;
}
