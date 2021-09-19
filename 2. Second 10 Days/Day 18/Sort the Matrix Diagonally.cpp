/*
Problem Title:  Sort the Matrix Diagonally
Problem URL:    https://leetcode.com/problems/sort-the-matrix-diagonally/

Description:    A matrix diagonal is a diagonal line of cells starting from some cell 
                in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end.
                For example, the matrix diagonal starting from mat[2][0],
                where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
                Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int Xc = 0, Yc = m-1;
        while(Xc != n)
        {
            int x = Xc, y = Yc;
            vector<int> diagonal;
            while(x < n && y < m)
                diagonal.push_back(mat[x++][y++]);
            
            sort(diagonal.begin(), diagonal.end());
            
            x = Xc; y = Yc;
            for (int i = 0; i < diagonal.size(); ++i, ++x, ++y)
                mat[x][y] = diagonal[i];
            
            (Yc != 0)? Yc-- : Xc++;
        }
        return mat;
    }
};