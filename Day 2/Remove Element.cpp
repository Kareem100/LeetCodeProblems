/*
Problem Title: Remove Element
Problem URL: https://leetcode.com/problems/remove-element/
Description: Given an integer array nums and an integer val, 
             remove all occurrences of val in nums in-place. 
             The relative order of the elements may be changed.
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
    int removeElement(vector<int>& nums, int val) {
        
        if (nums.size()==1 && nums[0] == val) {nums[0] = -1; return 0;}
        if (nums.size()==1 && nums[0] != val) {return 1;}
        
        int k = nums.size(), j = 0;
        for(;j<nums.size();++j)
            if (nums[j] == val) { nums[j] = -1; k--;}
           
        int i = 0; j = 1;
        while(j < nums.size())
            if (nums[i] == -1) 
            {
                if (nums[j] != -1) {swap(nums[i], nums[j]); i++;}
                j++;
            }
            else i++, j++;
        
        return k;
    }
};