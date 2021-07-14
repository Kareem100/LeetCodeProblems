/*
Problem Title: Reverse Integer
Problem URL: https://leetcode.com/problems/two-sum/
Description: Given a signed 32-bit integer x, return x with its digits reversed. 
             If reversing x causes the value to go outside the signed 
             32-bit integer range [-231, 231 - 1], then return 0.
             Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Difficulty: Easy
Language: C++
Category: Algorithms
*/

class Solution {
public:
    int reverse(int x) 
    {
        int reversedX=0, revCopyX=0;
        int digitsCnt=0;
        int checker = -2147483648;
        bool zero = false;
        if (x>0) checker=2147483647;
        while(x!=0)
        {
            digitsCnt++;
            if(digitsCnt==10)
            {
                revCopyX = reversedX;
                int y = x % 10;
                int z = checker  % 10;
                if(abs(z)<abs(y))zero=true;
                checker/=10;
                for (int i = 0; i < 9; ++i)
                {
                    int y = revCopyX % 10;
                    int z = checker  % 10;
                    if (abs(z)<abs(y)) zero=true;
                    else if (abs(z)>abs(y)) zero = false;
                    revCopyX/=10;
                    checker/=10;
                }
                if (zero) return 0;
            }
            
            int y = x%10;
            reversedX = reversedX*10+y;
            x/=10;
        }
        return reversedX;
    }
};