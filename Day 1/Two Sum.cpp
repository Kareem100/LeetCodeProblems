/*
Problem Title: Two Sum
Problem URL: https://leetcode.com/problems/two-sum/
Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
             You may assume that each input would have exactly one solution, and you may not use the same element twice.
             You can return the answer in any order.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i+1; j < nums.size();++j)
                if(nums[i] + nums[j] == target){
                    res.push_back(i); res.push_back(j);
                    break;
                }
        return res;
    }
};