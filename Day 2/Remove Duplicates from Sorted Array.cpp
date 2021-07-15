/*
Problem Title: Remove Duplicates from Sorted Array
Problem URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Description: Given an integer array nums sorted in non-decreasing order, 
             remove the duplicates in-place such that each unique element appears only once. 
             The relative order of the elements should be kept the same.

             Since it is impossible to change the length of the array in some languages, 
             you must instead have the result be placed in the first part of the array nums. 
             More formally, if there are k elements after removing the duplicates, 
             then the first k elements of nums should hold the final result. 
             It does not matter what you leave beyond the first k elements.
             
             Return k after placing the final result in the first k slots of nums.
             Do not allocate extra space for another array. 
             You must do this by modifying the input array in-place with O(1) extra memory.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() < 2) return nums.size();
        int k = nums.size(), i = 0, j = 1;
        while(j < nums.size())
            if (nums[i] == nums[j]) { nums[j] = -1000; j++; k--;}
            else {i = j; j++;}
        
        i = 1; j = 2;
        while(j < nums.size())
            if (nums[i] == -1000) 
            {
                if (nums[j] != -1000) {swap(nums[i], nums[j]); i++;}
                j++;
            }
            else i++, j++;
        
        return k;
    }
};