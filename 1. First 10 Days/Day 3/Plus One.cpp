/*
Problem Title: Plus One
Problem URL: https://leetcode.com/problems/plus-one/
Description:    Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
                The digits are stored such that the most significant digit is at the head of the list, 
                and each element in the array contains a single digit.
                You may assume the integer does not contain any leading zero, except the number 0 itself.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        for (int i = 0; i < digits.size(); ++i)
            result.push_back(digits[i]);
        
        int k = digits.size()-1; bool finished = false;
        while(k > -1)
        {
            if (result[k] == 9) result[k] = 0;
            else {result[k]++; finished = true; break;}
            k--;
        }
        if(!finished)
            result.emplace (result.begin(), 1);
            
        return result;
    }
};