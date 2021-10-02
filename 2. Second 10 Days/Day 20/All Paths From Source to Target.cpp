/*
Problem Title:  All Paths From Source to Target
Problem URL:    https://leetcode.com/problems/all-paths-from-source-to-target/submissions/

Description:    Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
                find all possible paths from node 0 to node n - 1 and return them in any order.
                The graph is given as follows: graph[i] is a list of all nodes,
                you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Difficulty: Medium
Language: C++
Category: Algorithms
*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>>q;
        q.push({0, {0}});
        
        while(!q.empty()) 
        {
            pair<int , vector<int>> node = q.front();
            q.pop();
            int value = node.first;
            
            if(node.second.back() == graph.size()-1) 
            {
                ans.push_back(node.second);
                continue;
            }
            
            for(int x : graph[value]) 
            {
                node.second.push_back(x);
                q.push({x , node.second});
                node.second.pop_back();
            }
        }
        
        return ans;
    }
};