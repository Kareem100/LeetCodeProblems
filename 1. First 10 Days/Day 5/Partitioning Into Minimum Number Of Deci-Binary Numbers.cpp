/*
Problem Title:  Partitioning Into Minimum Number Of Deci-Binary Numbers
Problem URL:    https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
Description:    A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
                For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

                Given a string n that represents a positive decimal integer, 
                return the minimum number of positive deci-binary numbers needed so that they sum up to n.
                
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (int i = 0; i < n.size(); ++i)
            if ((n[i]-'0') > max) max = (n[i]-'0');
        return max;
    }
};
