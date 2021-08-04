/*
Problem Title:  Maximum Subarray
Problem URL:    https://leetcode.com/problems/maximum-subarray/submissions/
Description:    Given an integer array nums, 
                find the contiguous subarray (containing at least one number) 
                which has the largest sum and return its sum.
                A subarray is a contiguous part of an array.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= currentSum + nums[i])
                currentSum += nums[i];
            else 
                currentSum = nums[i];
            if (currentSum > maxSum) maxSum = currentSum;
        }
        return maxSum;
    }
};