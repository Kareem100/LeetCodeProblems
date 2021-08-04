/*
Problem Title: Climbing Stairs
Problem URL: https://leetcode.com/problems/climbing-stairs/
Description:    You are climbing a staircase. It takes n steps to reach the top.
                Each time you can either climb 1 or 2 steps. 
                In how many distinct ways can you climb to the top?
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        if (n==3) return 3;
        if (n==4) return 5;
        if (n==5) return 8;
        if (n==6) return 13;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};