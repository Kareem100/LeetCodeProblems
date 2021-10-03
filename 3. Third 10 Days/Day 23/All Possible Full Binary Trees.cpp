/*
Problem Title:  All Possible Full Binary Trees
Problem URL:    https://leetcode.com/problems/all-possible-full-binary-trees/

Description:    Given an integer n, return a list of all possible full binary trees with n nodes. 
                Each node of each tree in the answer must have Node.val == 0.
                Each element of the answer is the root node of one possible tree. 
                You may return the final list of trees in any order.
                A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Difficulty: Medium
Language: C++
Category: Algorithms
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
private:
    map<int, vector<TreeNode*>> memo;
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!memo.count(n)) 
        {
            vector<TreeNode*> ans;
            if (n == 1)
                ans.push_back(new TreeNode(0));
            
            else if (n % 2 != 0) 
            {
                for (int i = 0; i < n; ++i) 
                {
                    int x = n - i - 1;
                    for (TreeNode* left : allPossibleFBT(i))
                        for (TreeNode* right : allPossibleFBT(x)) 
                        {
                            TreeNode* abc = new TreeNode(0);
                            abc->left = left;
                            abc->right = right;
                            ans.push_back(abc);
                        }
                }
            }
            
            memo.insert({n, ans});
        }
        
        return memo[n];
    }
    

};