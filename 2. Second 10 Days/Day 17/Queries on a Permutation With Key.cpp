/*
Problem Title:  Queries on a Permutation With Key
Problem URL:    https://leetcode.com/problems/queries-on-a-permutation-with-key/

Description:    Given the array queries of positive integers between 1 and m, 
                you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:
                In the beginning, you have the permutation P=[1,2,3,...,m].
                For the current i, find the position of queries[i] in the permutation P (indexing from 0) 
                and then move this at the beginning of the permutation P. 
                Notice that the position of queries[i] in P is the result for queries[i].
                Return an array containing the result for the given queries.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p; for (int i = 1; i <= m; ++i) p.push_back(i);
        vector<int> answers;
        for (int i = 0; i < queries.size(); ++i)
        {
            int j = 0;
            for (; j < p.size(); ++j) if (queries[i] == p[j]) break;
            answers.push_back(j);
            p.insert(p.begin(), p[j]);
            p.erase(p.begin()+j+1);
        }
        return answers;
    }
};