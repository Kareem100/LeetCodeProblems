/*
Problem Title:  Stone Game
Problem URL:    https://leetcode.com/problems/stone-game/
Description:    Alex and Lee play a game with piles of stones.  
                There are an even number of piles arranged in a row, 
                and each pile has a positive integer number of stones piles[i].
                The objective of the game is to end with the most stones.
                The total number of stones is odd, so there are no ties.
                Alex and Lee take turns, with Alex starting first.  
                Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.
                This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));

        for (int sz = 1; sz <= N; ++sz)
            for (int i = 0, j = sz - 1; j < N; ++i, ++j)
                if ((j + i) % 2 != 0)
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);

        return dp[1][N] > 0;
    }
};