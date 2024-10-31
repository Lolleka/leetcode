// https://leetcode.com/problems/unique-paths-iii/
// hard

#include <iostream>
#include <vector>
#include <utility>
#include <stack>

struct pos{
    int i;
    int j;
    int move;
    pos() : i(0), j(0), move(0) {}
    pos(int i, int j, int move) : i(i), j(j), move(move) {}
};

class Solution {
public:
    std::pair<int, int> locate_start(std::vector<std::vector<int>>& grid){
        int h = grid.size();
        int w = grid[0].size();
        for(int i = 0; i < w; ++i){
            for(int j = 0; j < h; ++j){
                if (grid[j][i] == 1) return std::pair<int, int>(i, j);
            }
        }
    }
    int count_free_tiles(std::vector<std::vector<int>>& grid){
        int h = grid.size();
        int w = grid[0].size();
        int c = 0;
        for(int i = 0; i < w; ++i){
            for(int j = 0; j < h; ++j){
                if (grid[j][i] == 0) c++;
            }
        }
        return c;
    }
    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        // backtracking solution
        int h = grid.size(); int w = grid[0].size();
        int paths_count = 0;
        std::vector<std::vector<bool>> stepped(h, std::vector<bool>(w, 0));
        std::stack<pos*> pos_stack;
        std::pair<int, int> start = locate_start(grid);
        int free_tiles = count_free_tiles(grid);
        pos_stack.push(new pos(start.first, start.second, 0));
        stepped[start.second][start.first] = true;
        // order of moves: right, down, left, up
        pos* current_pos;
        while(true){
            current_pos = pos_stack.top();
            int i = current_pos->i;
            int j = current_pos->j;
            int new_i = i; int new_j = j;
            // formulate new move
            int m = ++current_pos->move;
            // if we are formulating the next move at the start and
            // we have no more options, stop iterating
            if (m > 4){
                if (pos_stack.size()==1) break;
                else{
                    // backtrack one step
                    pos_stack.pop();
                    delete current_pos;
                    stepped[new_j][new_i] = false;
                }
            }else{
                // translate move into i and j update
                if (m == 1 && i+1 < w){  // move right
                    new_i = i + 1;
                } else if (m == 2 && j+1 < h){ // move down
                    new_j = j + 1;
                } else if (m == 3 && i-1 >= 0){ // move left
                    new_i = i - 1;
                } else if (m == 4 && j-1 >= 0){ // move up
                    new_j = j - 1;
                }
                // evaluate result of move
                if (grid[new_j][new_i] == 2){
                    if(pos_stack.size()-1 == free_tiles) paths_count++; // found a path
                }
                else if (grid[new_j][new_i] == 0 && !stepped[new_j][new_i]){ //valid
                    // put position on the stack
                    pos_stack.push(new pos(new_i, new_j, 0));
                    stepped[new_j][new_i] = true;
                }
            }

        }
        return paths_count;

    }
};

int main (int argc, char *argv[]) {
    std::vector<std::vector<int>> grid = {
        /*{1,0,0,0},{0,0,0,0},{0,0,2,-1}*/
        /*{1,0,0,0},{0,0,0,0},{0,0,0,2}*/
        {0,1},{2,0}
    };
    std::cout << Solution().count_free_tiles(grid) << std::endl;
    std::cout << Solution().uniquePathsIII(grid) << std::endl;
    return 0;
}
