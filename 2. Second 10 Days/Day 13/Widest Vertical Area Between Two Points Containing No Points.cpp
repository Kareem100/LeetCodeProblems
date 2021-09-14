/*
Problem Title:  Widest Vertical Area Between Two Points Containing No Points
Problem URL:    https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

Description:    Given n points on a 2D plane where points[i] = [xi, yi], 
                Return the widest vertical area between two points such that no points are inside the area.
                A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). 
                The widest vertical area is the one with the maximum width.
                Note that points on the edge of a vertical area are not considered included in the area.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> Xs; int maxWidth = 0;
        for (int i = 0; i < points.size(); ++i) Xs.push_back(points[i][0]);
        sort(Xs.begin(), Xs.end());
        for (int i = 1; i < Xs.size(); ++i)
            if (Xs[i] - Xs[i-1] > maxWidth) maxWidth = Xs[i] - Xs[i-1];
        return maxWidth;
    }
};