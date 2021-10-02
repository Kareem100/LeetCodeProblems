/*
Problem Title:  Finding the Users Active Minutes
Problem URL:    https://leetcode.com/problems/finding-the-users-active-minutes/

Description:    You are given the logs for users' actions on LeetCode, and an integer k. 
                The logs are represented by a 2D integer array logs where each logs[i] = [IDi, timei] 
                indicates that the user with IDi performed an action at the minute timei.
                Multiple users can perform actions simultaneously, and a single user can perform multiple actions in the same minute.
                The user active minutes (UAM) for a given user is defined as the number of unique minutes 
                in which the user performed an action on LeetCode. 
                A minute can only be counted once, even if multiple actions occur during it.
                You are to calculate a 1-indexed array answer of size k such that, 
                for each j (1 <= j <= k), answer[j] is the number of users whose UAM equals j.
                Return the array answer as described above.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> uamAns(k, 0);
        map<int, set<int>> mp;
        
        for (int i = 0; i < logs.size(); ++i)
        {
            map<int, set<int>>::iterator it = mp.find(logs[i][0]);
            if (it == mp.end()) 
            {
                set<int> st;
                st.insert(logs[i][1]);
                mp.insert({logs[i][0], st});
            }
            else 
                mp[logs[i][0]].insert(logs[i][1]);
        }
        
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
            uamAns[(itr->second).size()-1]++;
        
        return uamAns;
    }
};