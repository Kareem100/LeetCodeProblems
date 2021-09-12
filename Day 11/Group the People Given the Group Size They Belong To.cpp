/*
Problem Title:  Group the People Given the Group Size They Belong To
Problem URL:    https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
Description:    There are n people that are split into some unknown number of groups. 
                Each person is labeled with a unique ID from 0 to n - 1.

                You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. 
                For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

                Return a list of groups such that each person i is in a group of size groupSizes[i].

                Each person should appear in exactly one group, and every person must be in a group. 
                If there are multiple answers, return any of them. 
                It is guaranteed that there will be at least one valid solution for the given input.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector<vector<int>>groups;
        map<int, vector<int>> mp;
        map<int, vector<int>>::iterator it;
        
        for (int i = 0; i < groupSizes.size(); ++i)
            mp[groupSizes[i]].push_back(i);
        
        for(it=mp.begin(); it != mp.end(); ++it)
        {
            int groupSize = it->first, k=0;
            vector<int> persons = it->second;
            int bulks = persons.size()/groupSize;
            
            while(bulks--)
            {
                vector<int> newBulk;
                for(int i = 0; i < groupSize; ++i)
                    newBulk.push_back(persons[k++]);
                groups.push_back(newBulk);
            }
        }
        
        return groups;
    }
};