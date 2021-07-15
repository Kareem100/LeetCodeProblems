/*
Problem Title: Valid Parentheses
Problem URL: https://leetcode.com/problems/valid-parentheses/
Description: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
             determine if the input string is valid. An input string is valid if:
             1- Open brackets must be closed by the same type of brackets.
             2- Open brackets must be closed in the correct order.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '[')
                st.push(']');
            else if (s[i] == '{')
                st.push('}');
            else if (s[i] == '(')
                st.push(')');
            else if (st.empty() || s[i]!=st.top())
                    return false;
            else 
                st.pop();
        if(!st.empty()) return false;
        return true;
    }
};