/*
Problem Title:  Queries on Number of Points Inside a Circle
Problem URL:    https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
Description:    You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane.
                Multiple points can have the same coordinates.
                You are also given an array queries where queries[j] = [xj, yj, rj] 
                describes a circle centered at (xj, yj) with a radius of rj.
                For each query queries[j], compute the number of points inside the jth circle. 
                Points on the border of the circle are considered inside.
                Return an array answer, where answer[j] is the answer to the jth query.
                
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer; int cnt;
        for (int q = 0; q < queries.size(); ++q)
        {
            cnt = 0;
            for (int p = 0; p < points.size(); ++p)
                if (hypot(queries[q][0] - points[p][0], 
                          queries[q][1] - points[p][1]) <= queries[q][2]) cnt++;
            answer.push_back(cnt);
        }
        return answer;
    }
};
