/*
Problem Title:  Add Binary
Problem URL:    https://leetcode.com/problems/add-binary/submissions/
Description:    Given two binary strings a and b, return their sum as a binary string.
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string sum="", t="";
        if (a.size() > b.size())
        {
            for (int i = b.size(); i < a.size(); ++i) t += '0';
            b = t + b;
        }   
        else 
        {
            for (int i = a.size(); i < b.size(); ++i) t += '0';
            a = t + a;
        }
 
        int cnt=0;
        for (int i = a.size()-1; i > -1; --i)
        {
            int d = ((a[i]-'0') + (b[i]-'0') + cnt) % 2;
            cnt = ((a[i]-'0') + (b[i]-'0') + cnt) / 2;
            sum += (d + '0');
        }
        if (cnt==1) sum+='1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};