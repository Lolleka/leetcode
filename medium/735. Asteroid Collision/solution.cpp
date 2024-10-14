// https://leetcode.com/problems/asteroid-collision
// medium
#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> asteroidCollision(std::vector<int>& v){
        std::vector<int> s;
        s.push_back(v[0]);
        for (int i=1; i < v.size(); ++i){
            if (!s.empty() && v[i] < 0 && s.back() > 0){
                while( !s.empty() && -v[i] > s.back() && s.back() > 0){
                    s.pop_back();
                }
                if (!s.empty() && -v[i] == s.back()) {
                    s.pop_back();
                }else if (s.empty() || s.back() < 0){
                    s.push_back(v[i]);
                }
            }else{
                s.push_back(v[i]);
            }
        }
        return s;
    }
};

int main(){
    std::vector<int> v = {-87,-724,-947,645,896,-377,222,-751,-799,-644,-803,584,263,134,-296,283,181,-52,-556,3,426,-328,631,-544,350,615,283,845,-282,-999,914,332,9,136,839,712};
    for(int i: v) std::cout << i << " ";
    std::cout << std::endl;
    std::vector<int> r = Solution().asteroidCollision(v);
    for(int i: r) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
