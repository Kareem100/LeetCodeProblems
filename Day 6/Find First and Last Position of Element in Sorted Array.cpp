/*
Problem Title:  Find First and Last Position of Element in Sorted Array
Problem URL:    https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Description:    Given an array of integers nums sorted in ascending order, 
                find the starting and ending position of a given target value.
                If target is not found in the array, return [-1, -1].
                You must write an algorithm with O(log n) runtime complexity.
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(getFirstOccurrence(nums, target));
        result.push_back(getLastOccurrence(nums, target));
        return result;
    }

private:
    int getFirstOccurrence(vector<int> nums, int target)
    {
        int start = 0, end = nums.size()-1, mid;
        int occurrence = -1;
        while(start <= end)
        {
            mid = (start+end) / 2;
            if (nums[mid] == target) 
            {
                occurrence = mid;
                end = mid-1;
            }
            else if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return occurrence;
    }
    
private:
    int getLastOccurrence(vector<int> nums, int target)
    {
        int start = 0, end = nums.size()-1, mid;
        int occurrence = -1;
        while(start <= end)
        {
            mid = (start+end) / 2;
            if (nums[mid] == target) 
            {
                occurrence = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return occurrence;
    }
};
