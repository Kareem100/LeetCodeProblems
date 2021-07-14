/*
Problem Title: Palindrome Number
Problem URL: https://leetcode.com/problems/palindrome-number/
Description: Given an integer x, return true if x is palindrome integer.
            An integer is a palindrome when it reads the same backward as forward. 
            For example, 121 is palindrome while 123 is not.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        vector<int> digits;
        while(x!=0)
        {
            digits.push_back(x%10);
            x/=10;
        }
        int loopLen = (digits.size()+1)/2;
        for(int i = 0; i < loopLen; ++i)
            if(digits[i] != digits[digits.size()-1-i]) return false;
        
        return true;
    }
};