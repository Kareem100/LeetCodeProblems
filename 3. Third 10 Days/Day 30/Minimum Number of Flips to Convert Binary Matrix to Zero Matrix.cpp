/*
Problem Title:  Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
Problem URL:    https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

Description:    Given a m x n binary matrix mat. In one step, you can choose one cell and flip it 
                and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). 
                A pair of cells are called neighbors if they share one edge.
                Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
                A binary matrix is a matrix with all cells equal to 0 or 1 only.
                A zero matrix is a matrix with all cells equal to 0.

Difficulty: Hard
Language: C++
Category: Algorithms
*/


class Solution {
    
private:
    int rows, cols;
    int dp[1111], pw2[13];
    
    void flip(vector<vector<int>>& mat, int rowIdx, int colIdx) {
        mat[rowIdx][colIdx] = 1 - mat[rowIdx][colIdx];
        if(rowIdx)
            mat[rowIdx-1][colIdx] = 1 - mat[rowIdx - 1][colIdx];
        if(colIdx)
            mat[rowIdx][colIdx-1] = 1 - mat[rowIdx][colIdx - 1];
        if(rowIdx < rows-1)
            mat[rowIdx + 1][colIdx] = 1 - mat[rowIdx + 1][colIdx];
        if(colIdx < cols-1)
            mat[rowIdx][colIdx + 1] = 1 - mat[rowIdx][colIdx + 1];
    }
    
    int solver(vector<vector<int>>& mat) {
        int s = 0;
        int i, j, k=0;
        vector<vector<int>> n;
        
        for(i=0; i < rows; ++i)
        {
            vector<int> t;
            for(j=0; j < cols; ++j)
            {
                s += mat[i][j] * pw2[k];
                t.push_back(mat[i][j]);
                k++;
            }
            n.push_back(t);
        }
        
        if(dp[s] != -1)
            return dp[s];
        
        dp[s] = INT_MAX;
        
        for(i = 0; i < rows; ++i)
            for(j = 0; j < cols; ++j)
            {
                flip(n, i, j);
                int nxt = solver(n);
                if(nxt != INT_MAX)
                    dp[s] = min(dp[s], nxt + 1);
                flip(n, i, j);
            }
        
        return dp[s];
    }
    
public:
    int minFlips(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        pw2[0] = 1;
        
        for(int i = 1; i < 13; ++i)
            pw2[i] = pw2[i-1] <<1;
        
        int minimumFlips = solver(mat);
        if(minimumFlips == INT_MAX)
            return -1;
        
        return minimumFlips;
    }
};