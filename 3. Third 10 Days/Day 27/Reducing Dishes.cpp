/*
Problem Title:  Reducing Dishes
Problem URL:    https://leetcode.com/problems/reducing-dishes/

Description:    A chef has collected data on the satisfaction level of his n dishes. 
                Chef can cook any dish in 1 unit of time.
                Like-time coefficient of a dish is defined as the time taken to cook that dish 
                including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
                Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
                Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Difficulty: Hard
Language: C++
Category: Algorithms
*/

class Solution {
    
public:
    int maxSatisfaction(vector<int>& arr) {
        
        int sz = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> dp(sz, 0);
        int ans = 0, currentSum = arr[sz-1];
        ans = max(ans, currentSum);
        dp[sz-1] = arr[sz-1];
            
        for (int i = sz-2; i > -1; --i)
        {
            dp[i] = dp[i+1] + arr[i];
            currentSum += dp[i];
            ans = max(ans, currentSum);
        }
        
        return ans;
    }
    
};