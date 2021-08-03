/*
Problem Title:  Length of Last Word
Problem URL: https://leetcode.com/problems/length-of-last-word/
Description: Given a string s consists of some words separated by some number of spaces, 
             return the length of the last word in the string.
             A word is a maximal substring consisting of non-space characters only.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isSpace = false; int trimmed = 0;
        for (int i = s.size() -1 ; i > -1; --i)
        {
            if (s[i] != ' ') {isSpace = true; continue;}
            if (s[i] == ' ' && !isSpace) {trimmed++; continue;}
            if (s[i] == ' ' && isSpace) return s.size() - i - 1 - trimmed;
        }
        return s.size() - trimmed;
    }
};