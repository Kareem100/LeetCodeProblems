/*
Problem Title:  Minimize Maximum Pair Sum in Array
Problem URL:    https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
Description:    The pair sum of a pair (a,b) is equal to a + b. 
                The maximum pair sum is the largest pair sum in a list of pairs.
                For example, if we have pairs (1,5), (2,3), and (4,4), 
                the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
                Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
                    Each element of nums is in exactly one pair, and
                    The maximum pair sum is minimized.
Return the minimized maximum pair sum after optimally pairing up the elements.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int start=0, end=nums.size()-1, minSum=0, size=nums.size()/2;
        sort(nums.begin(), nums.end());
        while(size--)
        {
            if (nums[start] + nums[end] > minSum) minSum = nums[start] + nums[end];
            start++; end--;
        }
        return minSum;
    }
};
