// https://leetcode.com/problems/median-of-two-sorted-arrays/
// hard

#include <iostream>
#include <vector>

class Solution {
    double findMedianSingleArray(std::vector<int>&nums){
        int n = nums.size();
        if (n % 2 == 0) return double(nums[n/2-1]+nums[n/2])/2;
        else return double(nums[n/2]);
    }
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.empty()) return findMedianSingleArray(nums2);
        if (nums2.empty()) return findMedianSingleArray(nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int i = 0, j = n+1;
        int i1 = -1;
        int i2 = -1;
        int j1 = n1;
        int j2 = n2;
        int a = 0, b = 0;

        while((n%2==0 && i<j-1) || (n % 2 == 1 && i < j)){
            if(i1+1 < j1 && i2+1 < j2){
                if(nums1[i1+1] > nums2[i2+1]){
                    a = nums2[++i2];
                }else{
                    a = nums1[++i1];
                } 
            }
            else if(i1+1 < j1) a = nums1[++i1];
            else if(i2+1 < j2) a = nums2[++i2];

            if(j1-1 > i1 && j2-1 > i2){
                if(nums1[j1-1] < nums2[j2-1]){
                    b = nums2[--j2];
                }else{
                    b = nums1[--j1];
                } 
            }
            else if(j1-1 > i1) b = nums1[--j1];
            else if(j2-1 > i2) b = nums2[--j2];
            j--; i++;
            std::cout << "a: " << a << ", b: " << b << std::endl;
        }
        double res = 0;
        if (j == i+1 && n % 2 == 0){
            std::cout << std::endl;
            res = double(a+b)/2;

        } else if ( j == i && n % 2 == 1){
            std::cout << std::endl;
            res = double(a);
        }
        return res;
        
    }
};


int main (int argc, char *argv[]) {
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2};
    std::cout << Solution().findMedianSortedArrays(nums1, nums2) << std::endl;
    
    return 0;
}
