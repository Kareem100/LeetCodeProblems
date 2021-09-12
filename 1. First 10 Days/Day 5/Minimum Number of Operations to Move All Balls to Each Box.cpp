/*
Problem Title:  Minimum Number of Operations to Move All Balls to Each Box
Problem URL:    https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
Description:    You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' 
                if the ith box is empty, and '1' if it contains one ball.
                In one operation, you can move one ball from a box to an adjacent box. 
                Box i is adjacent to box j if abs(i - j) == 1. 
                Note that after doing so, there may be more than one ball in some boxes.
                Return an array answer of size n, where answer[i] is the minimum number of operations 
                needed to move all the balls to the ith box.
                Each answer[i] is calculated considering the initial state of the boxes.
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result;
        int op;
        for (int i = 0; i < boxes.size(); ++i)
        {
            op = 0;
            for (int j = 0; j < boxes.size(); ++j)
                if(boxes[j] == '1') op += abs(i-j);
            result.push_back(op);
        }
        return result;
    }
};
