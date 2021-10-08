/*
Problem Title:  Partition Labels
Problem URL:    https://leetcode.com/problems/partition-labels/

Description:    You are given a string s. 
                We want to partition the string into as many parts as possible so that each letter appears in at most one part.
                Return a list of integers representing the size of these parts.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans; int first = 0, max = -1;
        set<char> st;
        
        for (int i = 0; i < s.size(); ++i) {
            if (i == max) {
                ans.push_back(max-first+1);
                max = -1; first = i+1;
                st.clear();
                continue;
            }
            
            bool isFound = false;
            int szBefore = st.size();
            st.insert(s[i]);
            int szAfter = st.size();
            if (szBefore != szAfter)
                for (int j = s.size() - 1; j > i ; --j)
                    if (s[i] == s[j]) {
                        if (j > max)
                            max = j;
                        isFound = true;
                        break;
                    }
            
            if (!isFound && i > max) {
                ans.push_back(1);
                max = -1; first = i+1;
                st.clear();
            }
        }
        
        return ans;
    }
};