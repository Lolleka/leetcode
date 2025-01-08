// https://leetcode.com/problems/number-of-provinces/
// medium
// #depth-first-search, #breadth-first-search, #union-find, #graph
#include <iostream>
#include <vector>
#include <stack>

class Solution {
    bool isIsolated(std::vector<int>& city){
        int sum = 0;
        for(int c: city) sum += c;
        return sum == 1;
    }
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int provinces = 0;
        int cities = isConnected.size();
        std::vector<bool> visited(cities, false);
        for (int c = 0; c < cities; c++){
            if(isIsolated(isConnected[c])) {
                provinces++;
                visited[c] = true;
            }
            else if(!visited[c]){
               // bfs 
                std::stack<int> s;
                s.push(c);
                while(!s.empty()){
                    int i = s.top();
                    s.pop();
                    visited[i] = true;
                    for(int nc=0; nc < cities; nc++){
                        if (!visited[nc] && isConnected[i][nc]) s.push(nc);
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    isConnected ={{1,0,0},{0,1,0},{0,0,1}}; 
    isConnected ={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}}; 
    std::cout << Solution().findCircleNum(isConnected) << std::endl;
    return 0;
}
