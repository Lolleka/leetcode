// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
// medium
// #depth-first-search, #breadth-first-search, #graph
#include <iostream>
#include <vector>
#include <stack>

struct adjItem{
    int val;
    int direct;
};

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        // build adjacency list where each entry also specifies which direction the edge
        // is going
        int flips = 0;
        std::vector<std::vector<adjItem>> adj(n);
        for(auto conn: connections){
            adj[conn[0]].push_back(adjItem({conn[1], 1}));
            adj[conn[1]].push_back(adjItem({conn[0], 0}));
        }
        std::stack<adjItem> s;
        std::vector<bool> visited (n, false);
        for(adjItem a: adj[0])
            s.push(a);
        visited[0] = true;
        while(!s.empty()){
            adjItem current = s.top(); s.pop();
            visited[current.val] = true;
            if (current.direct) flips++;
            for(adjItem a: adj[current.val])
                if (!visited[a.val])
                    s.push(a);
        }
        return flips; 
    }
};

int main (int argc, char *argv[]) {
    int n = 6;
    std::vector<std::vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}}; 
    std::cout << Solution().minReorder(n,connections) << std::endl;
    return 0;
}
