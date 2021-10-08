/*
Problem Title:  All Elements in Two Binary Search Trees
Problem URL:    https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

Description:    Given two binary search trees root1 and root2.
                Return a list containing all the integers from both trees sorted in ascending order.

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
    vector<int> sortedElements;
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        setElements(root1, v1);
        setElements(root2, v2);
        
        return mergeElements(v1, v2);
    }
    
    void setElements(TreeNode* root1, vector<int>& v) {
        if (root1 == NULL) return;
        setElements(root1->left, v);
        v.push_back(root1->val);
        setElements(root1->right, v);
    }
    
    vector<int> mergeElements(vector<int> v1, vector<int> v2) {
        vector<int> mergedElements;
        v1.push_back(INT_MAX);
        v2.push_back(INT_MAX);
        
        int i=0, j=0, k = v1.size() + v2.size() - 2;
        for (int m = 0; m < k; ++m)
            if (v1[i] < v2[j])
                mergedElements.push_back(v1[i++]);
            else 
                mergedElements.push_back(v2[j++]);
        
        return mergedElements;
    }
};