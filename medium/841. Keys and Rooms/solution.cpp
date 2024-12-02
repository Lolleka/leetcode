// https://leetcode.com/problems/keys-and-rooms
// medium
// #depth-first-search, #breadth-first-search, #graph

#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int> >& rooms) {
        int visited = 0;
        std::stack<int> stack;
        stack.push(0);
        while(!stack.empty()){
            int room = stack.top();
            if (rooms[room].size() == 1 && rooms[room][0] == -1) {
                stack.pop();
                continue;
            }
            visited++;
            stack.pop();
            for (int key: rooms[room]) stack.push(key);
            rooms[room].clear();
            rooms[room].push_back(-1);
        }
        return visited == rooms.size();
    }
};

int main() {
    Solution solution;
    /* std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}}; */
    std::vector<std::vector<int>> rooms = {{1,3}, {3,0,1}, {2}, {0}};
    std::cout << solution.canVisitAllRooms(rooms) << std::endl;
    return 0;
}    
