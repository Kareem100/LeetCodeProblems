/*
Problem Title:  Max Increase to Keep City Skyline
Problem URL:    https://leetcode.com/problems/max-increase-to-keep-city-skyline/
Description:    There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. 
                You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.

                A city's skyline is the the outer contour formed by all the building when viewing the side of the city from a distance. 
                The skyline from each cardinal direction north, east, south, and west may be different.

                We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). 
                The height of a 0-height building can also be increased. However, 
                increasing the height of a building should not affect the city's skyline from any cardinal direction.

                Return the maximum total sum that the height of the buildings can be increased by 
                without changing the city's skyline from any cardinal direction.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> horizontalScrapers, verticalScrapers; int max, sum = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            max = -1;
            for (int j = 0; j < grid.size(); ++j)
                if (grid[i][j] > max) max = grid[i][j];
            horizontalScrapers.push_back(max);
        }
        for (int i = 0; i < grid.size(); ++i)
        {
            max = -1;
            for (int j = 0; j < grid.size(); ++j)
                if (grid[j][i] > max) max = grid[j][i];
            verticalScrapers.push_back(max);
        }
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid.size(); ++j)
                sum += (min(horizontalScrapers[i], verticalScrapers[j]) - grid[i][j]);
            horizontalScrapers.push_back(max);
        
        return sum;
    }
};