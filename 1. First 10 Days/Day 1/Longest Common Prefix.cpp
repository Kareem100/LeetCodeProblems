/*
Problem Title: Longest Common Prefix
Problem URL: https://leetcode.com/problems/longest-common-prefix/
Description: Write a function to find the longest common prefix string amongst an array of strings.
            If there is no common prefix, return an empty string "".            
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        for (int j = 0; j < strs[0].size(); ++j)
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i)
                if(j >= strs[i].size() || c!=strs[i][j]) 
                    return commonPrefix;
            commonPrefix+=c;
        }
        return commonPrefix;
    }
};