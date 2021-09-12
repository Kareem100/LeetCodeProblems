/*
Problem Title:  Search in Rotated Sorted Array
Problem URL:    https://leetcode.com/problems/search-in-rotated-sorted-array/
Description:    There is an integer array nums sorted in ascending order (with distinct values).
                Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
                such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
                For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
                Given the array nums after the rotation and an integer target, 
                return the index of target if it is in nums, or -1 if it is not in nums.
                You must write an algorithm with O(log n) runtime complexity.
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        while(start <= end)
        {
            mid = (start+end)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target && target < nums[mid]) end = mid-1;
                else start = mid+1;
            }
            else 
            {
                if (nums[mid] < target && target <= nums[end]) start = mid+1;
                else end = mid-1;
            }
        }
        return -1;
    }
};