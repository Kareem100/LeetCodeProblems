/*
Problem Title:  Sort an Array
Problem URL:    https://leetcode.com/problems/sort-an-array/
Description:    Given an array of integers nums, sort the array in ascending order.
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    
private:
    void mergeSort(vector<int>& nums, int start, int end)
    {
        if (start<end){
            int mid = (start+end)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, start, mid, end);    
        }
    }

private:
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        vector<int> firstHalf;
        for (int i = start; i <= mid; ++i)
            firstHalf.push_back(nums[i]);
        int left=start, right=mid+1, k=start; 
        while(left<=mid&&right<=end)
        {
            if (firstHalf[left-start] < nums[right])
                {nums[k++] = firstHalf[left-start]; left++;}
            else
                nums[k++] = nums[right++];
        }
        while(left<=mid)
           {nums[k++] = firstHalf[left-start]; left++;}
        while(right<=end)
            nums[k++] = nums[right++];
    }
};