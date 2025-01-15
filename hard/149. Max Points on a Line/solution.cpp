// https://leetcode.com/problems/max-points-on-a-line
// hard
// #array, #hash-table, #math, #geometry

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>
#include <numeric>

template <typename Number>
Number GCD(Number u, Number v) {
    while (v != 0) {
        Number r = u % v;
        u = v;
        v = r;
    }
    return u;
}

std::pair<int,int> get_canonical_fractional(int a, int b) {
    int gcd = GCD<int>(std::abs(a), std::abs(b));
    a /= gcd;
    b /= gcd;
    return b < 0 ? std::make_pair(-a, -b) : std::make_pair(a, b);
}

// Line function of two points , a and b, and the equation is
// y = x(b.y - a.y) / (b.x - a.x) + (b.x * a.y - a.x * b.y) / (b.x - a.x).
struct Line {
    // Store the numerator and denominator pair of slope unless the line is
    // parallel to y-axis that we store 1/0.  
    std::pair <int, int> slope;
    // Store the numerator and denominator pair of the y-intercept unless
    // the line is parallel to y-axis that we store the x-intercept.     
    std::pair <int, int> intercept;
    Line(const std::vector<int>& a, const std::vector<int>& b) :
        slope(a[0] != b[0] ? get_canonical_fractional(b[1] - a[1], b[0] - a[0]) : std::make_pair(1, 0)),
        intercept(a[0] != b[0] ? get_canonical_fractional(b[0] * a[1] - a[0] * b[1],  b[0] - a[0]) : std::make_pair(a[0], 1))
    {}

    bool operator==(const Line& other) const{
        return (slope.first == other.slope.first &&
                slope.second == other.slope.second &&
                intercept.first == other.intercept.first &&
                intercept.second == other.intercept.second);
    }
};

// Hash function for Line.
struct HashLine {
    std::size_t operator()(const Line& l) const {
        return std::hash<int>()(l.slope.first) ^
               std::hash<int>()(l.slope.second) ^
               std::hash<int>()(l.intercept.first) ^
               std::hash<int>()(l.intercept.second);
    }
};

class Solution {

public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        std::unordered_map<Line, int, HashLine> map;
        int n = 0;
        for(int i = 0; i < points.size(); ++i){
            for(int j = i+1; j < points.size(); ++j){
                if(j != i){
                    n++;
                    Line line = Line(points[i],points[j]);
                    auto it = map.find(line);
                    if(it != map.end()) map[line]++;
                    else map[line] = 1;
                    /*std::cout << i << " " << j <<" " << n << std::endl;*/
                }
            }
        }
        int max = 0;
        for(auto& it: map){
            if (it.second > max) max = it.second;
        }
        // max represents the edges of a complete graph with v vertices
        // max = v(v-1)/2
        // 2*max = v**2 - v
        // v = (1+sqrt(1+4*2*max))/2
        return static_cast<int>(1+std::sqrt(1+4*2*max))/2;
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    /*std::vector<std::vector<int>> points = {{1,1},{2,2}, {3,3}, {1,2}};*/
    std::cout <<  Solution().maxPoints(points) << std::endl;
    
    return 0;
}
