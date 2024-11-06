// https://leetcode.com/problems/rotting-oranges
// medium
#include <iostream>
#include <vector>
#include <utility>

class Solution {

    bool allFresh(std::vector<std::vector<int> >& grid){
        for(int j = 0; j < grid.size(); j++){
            for(int i = 0; i < grid[0].size(); i++){
                if(grid[j][i] == 2) return false;
            }
        }
        return true;
    }

    bool allRotten(std::vector<std::vector<int> >& grid){
        for(int j = 0; j < grid.size(); j++){
            for(int i = 0; i < grid[0].size(); i++){
                if(grid[j][i] == 1) return false;
            }
        }
        return true;
    }

    bool emptyGrid(std::vector<std::vector<int> >& grid){
        for(int j = 0; j < grid.size(); j++){
            for(int i = 0; i < grid[0].size(); i++){
                if(grid[j][i] > 0) return false;
            }
        }
        return true;
    }

    bool willRot(std::vector<std::vector<int> >& grid, int i, int j){
        bool up = (j > 0 && grid[j-1][i] == 2);
        bool down = (j < grid.size() - 1 && grid[j+1][i] == 2);
        bool left = (i > 0 && grid[j][i-1] == 2);
        bool right = (i < grid[0].size() - 1 && grid[j][i+1] == 2);
        return up || down || left || right;
    }

    int makeStep(std::vector<std::vector<int> >& grid){
        std::vector<std::pair<int, int> > turning;
        for(int j = 0; j < grid.size(); j++){
            for(int i = 0; i < grid[0].size(); i++){
                if(grid[j][i] == 1 && willRot(grid, i, j)){
                    turning.push_back(std::make_pair(i, j));
                }
            }
        }
        int n = turning.size();
        for (auto p : turning){
            grid[p.second][p.first] = 2;
        }
        return n;
    }

public:
    int orangesRotting(std::vector<std::vector<int> >& grid) {
        if (emptyGrid(grid)) return 0;
        if (allFresh(grid)) return -1;
        if (allRotten(grid)) return 0;
        int n = 0;

        while(!allRotten(grid)){
            int t = makeStep(grid);
            if (t == 0 && !allRotten(grid)) return -1;
            n++;
        }
        return n;
    }
};

int main(int argc, char const *argv[]){
    std::vector<std::vector<int> > grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    grid = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };
    grid = {
        {0,2}
    };
    grid = {{2},{2},{1},{0},{1},{1}};
    std::cout << Solution().orangesRotting(grid) << std::endl;
    return 0;
}
