// https://leetcode.com/problems/rectangle-overlap/
// easy

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int r = 2; int t = 3;
            int l = 0; int b = 1;
            return !(rec1[r] <= rec2[l] || rec1[l] >= rec2[r] ||
                    rec1[b] >= rec2[t] || rec1[t] <= rec2[b]);
        }
};

int main(){
    vector<int> rec1{0,0,1,1};
    vector<int> rec2{0,1,2,2};
    cout << boolalpha << Solution().isRectangleOverlap(rec1, rec2) << endl;
    return 0;
}
