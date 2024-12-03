// https://leetcode.com/problems/equal-row-and-column-pairs
// medium
// #array, #hash-table, #matrix, #simulation

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class Solution {
    std::string hashVector(const std::vector<int>& v){
        std::string hash = std::to_string(v[0]);
        for(int i = 1; i < v.size(); ++i) hash += "-" + std::to_string(v[i]);
        return hash;
    }
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        std::unordered_map<std::string, int> hashRows;
        auto v = grid[0];
        int n = grid.size();
        int count = 0;
        std::string hash = "";
        // store multiplicities in the rows hash table
        for(int i = 0; i < n; ++i){
            hash = hashVector(grid[i]); 
            /*std::cout << "row hash: " << hash << std::endl;*/
            auto it = hashRows.find(hash);
            if (it == hashRows.end()) hashRows[hash] = 1;
            else hashRows[hash] += 1;
        }
        // iterate columns and lookup multiplicities 
        for(int i = 0; i < n; ++i) {
            std::vector<int> col;
            for(int j = 0; j < n; ++j) col.push_back(grid[j][i]);
            hash = hashVector(col);
            /*std::cout << "col hash: " << hash << std::endl;*/
            auto it = hashRows.find(hash);
            if(it != hashRows.end()) count += (*it).second;
        }
        return count;
        // hash the rows
        // hash the columns and lookup in the rows hash table
        
    }
};

int main (int argc, char *argv[]) {
    /*std::vector<std::vector<int>> grid = {*/
    /*    {3,2,1},*/
    /*    {1,7,6},*/
    /*    {2,7,7}*/
    /*};*/
    std::vector<std::vector<int>> grid = {
        {3,1,2,2},
        {1,4,4,5},
        {2,4,2,2},
        {2,4,2,2}
    };
    std::cout << Solution().equalPairs(grid) << std::endl;
    return 0;
}
