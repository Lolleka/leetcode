// https://leetcode.com/problems/image-overlap/
// medium

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
    int overlap(vector< vector<int> >& image1, vector< vector<int> >& image2, int x, int y){
        // translate image2 wrt image1
        int l = image1.size();
        assert ( abs(x) < l && abs(y) < l );
        int sx = x > 0 ? x : 0;
        int ex = x < 0 ? l+x-1 : l-1;
        int sy = y > 0 ? y : 0;
        int ey = y < 0 ? l+y-1 : l-1;
        int o = 0;
        for (int i = sx; i <= ex; i++){
            for (int j = sy; j <= ey; j++){
                if (image1[i][j] && image2[i-x][j-y]) o++;
            }
        }
        return o;

    }
    public:
        int largestOverlap(vector<vector<int>>& image1, vector<vector<int>>& image2) {
            assert (image1.size() == image2.size());
            int l = image1.size();
            int o = 0;
            for (int x=-l+1; x<l; x++){
                for (int y=-l+1; y<l; y++){
                    int new_o = overlap(image1, image2, x, y);
                    if (new_o > o) o = new_o;
                }
            }
            return o;
        }
};

int main(){
    vector<vector<int>> image1 = {{0,0,1},{0,1,0},{0,0,0}};
    vector<vector<int>> image2 = {{0,0,1},{0,1,0},{0,0,0}};
    cout << Solution().largestOverlap(image1, image2) << endl;
    return 0;
}
