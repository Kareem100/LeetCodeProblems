/*
Problem Title:  Unique Paths III
Problem URL:    https://leetcode.com/problems/unique-paths-iii/

Description:    You are given an m x n integer array grid where grid[i][j] could be:

                (1) representing the starting square. There is exactly one starting square.
                (2) representing the ending square. There is exactly one ending square.
                (0) representing empty squares we can walk over.
                (-1) representing obstacles that we cannot walk over.
                Return the number of 4-directional walks from the starting square to the ending square, 
                that walk over every non-obstacle square exactly once.

Difficulty: Hard
Language: C++
Category: Algorithms
*/

class Solution {
    
private:
    vector<vector<int>> grid;
    int startI, startJ;
    int emptySquares;
    
    int getPaths(int i, int j, int emptySquares) 
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return 0;
        
        if (emptySquares == 0 && grid[i][j] == 2)
            return 1;
        
        if (grid[i][j] == -1 || grid[i][j] == 2 || grid[i][j] == 5)
            return 0;
        
        
        grid[i][j] = 5;
        int ans = getPaths(i+1, j, emptySquares-1) + getPaths(i, j+1, emptySquares-1) +
                  getPaths(i-1, j, emptySquares-1) + getPaths(i, j-1, emptySquares-1);
        grid[i][j] = 0;
        
        return ans;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& matrix) {
        grid = matrix;
        int n = grid.size();
        int m = grid[0].size();
        int emptySquares = 0;
        int startI, startJ;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 0 || grid[i][j] == 1) 
                {
                    emptySquares++;
                    if (grid[i][j] == 1)
                    {
                        startI = i;
                        startJ = j;
                    }
                }
        
        return getPaths(startI, startJ, emptySquares);
    }
    
};