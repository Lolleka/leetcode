// https://leetcode.com/problems/trapping-rain-water
// hard
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
std::vector<int> sort_indices(const std::vector<T> &v, bool reverse = false){
    // initialize original index locations
    std::vector<int> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::stable_sort(idx.begin(), idx.end(),
            [&v, reverse](int i1, int i2) { return reverse ? v[i1] > v[i2] : v[i1] < v[i2]; });
    return idx;
}

class Solution{
    int integrate(std::vector<int>& height, int i, int j){
        int l = std::min(height[i], height[j]);
        int area=0;
        if (j < i){ int t=j; j=i; i=t; } 
        for(int k=i+1; k<j; k++) area+=l-height[k];
        return area;
    }
public:
    int trap(std::vector<int>& height){
        std::vector<int> idx_max = sort_indices(height, true);
        int water = 0;
        int l = idx_max[0];
        int r = idx_max[0];
        for (int i = 1; i < idx_max.size(); ++i){
            int k = idx_max[i];
            if (k < l){
                water += integrate(height, k, l); 
                l = k;
            }else if (k > r){
                water += integrate(height, r, k); 
                r = k;
            }
        }
        return water;
    }
};

int main(){
    std::vector<int> height = {4,2,0,3,2,5,1,2,0,0,3};
    std::cout << Solution().trap(height) << std::endl;
    return 0;
}
