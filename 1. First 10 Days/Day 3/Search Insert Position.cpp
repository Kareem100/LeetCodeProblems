/*
Problem Title:  Search Insert Position
Problem URL: https://leetcode.com/problems/search-insert-position/
Description: Given a sorted array of distinct integers and a target value, 
             return the index if the target is found. 
             If not, return the index where it would be if it were inserted in order.
             You must write an algorithm with O(log n) runtime complexity.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        bool found = false;
        while(start <= end)
        {
            mid = (start+end)/2;
            if (nums[mid] == target)
            {
                found = true;
                break;
            }
            if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        if (found) return mid;
        return start;
    }
};