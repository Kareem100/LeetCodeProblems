/*
Problem Title:  Maximum Binary Tree
Problem URL:    https://leetcode.com/problems/maximum-binary-tree/

Description:    You are given an integer array nums with no duplicates. 
                A maximum binary tree can be built recursively from nums using the following algorithm:
                1. Create a root node whose value is the maximum value in nums.
                2. Recursively build the left subtree on the subarray prefix to the left of the maximum value.
                3. Recursively build the right subtree on the subarray suffix to the right of the maximum value.
                Return the maximum binary tree built from nums.

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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }

    TreeNode* constructTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int maxIdx = getMaxIdx(nums, start, end);
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = constructTree(nums, start, maxIdx-1);
        root->right = constructTree(nums, maxIdx+1, end);
        return root;
    }
 
    int getMaxIdx (vector<int>& arr, int start, int end)
    {
        int maxIdx=start;
        while (start <= end) {
            if (arr[maxIdx] < arr[start]) maxIdx = start;
            start++;
        }
        return maxIdx;
    }
};