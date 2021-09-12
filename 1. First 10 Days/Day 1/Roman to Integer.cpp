/*
Problem Title: Roman to Integer
Problem URL: https://leetcode.com/problems/roman-to-integer/
Description: Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

            Symbol       Value
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
            For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

            Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

            I can be placed before V (5) and X (10) to make 4 and 9. 
            X can be placed before L (50) and C (100) to make 40 and 90. 
            C can be placed before D (500) and M (1000) to make 400 and 900.
            Given a roman numeral, convert it to an integer.
            
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) 
        {
            if(s[i] == 'I')
            {
                if (i+1 != s.size() && s[i+1] == 'V')
                    res += 4, i++;
                else if (i+1 != s.size() && s[i+1] == 'X')
                    res += 9, i++;
                else 
                    res++;
            }
            else if (s[i] == 'X')
            {
                if (i+1 != s.size() && s[i+1] == 'L')
                    res += 40, i++;
                else if (i+1 != s.size() && s[i+1] == 'C')
                    res += 90, i++;
                else 
                    res += 10;
            }
            else if (s[i] == 'C')
            {
                if (i+1 != s.size() && s[i+1] == 'D')
                    res += 400, i++;
                else if (i+1 != s.size() && s[i+1] == 'M')
                    res += 900, i++;
                else 
                    res += 100;
            }
            else if (s[i] == 'V') res += 5;
            else if (s[i] == 'L') res += 50;
            else if (s[i] == 'D') res += 500;
            else res += 1000;
        }
        return res;
    }
};