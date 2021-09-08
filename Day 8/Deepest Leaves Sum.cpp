/*
Problem Title:  Deepest Leaves Sum
Problem URL:    https://leetcode.com/problems/deepest-leaves-sum/
Description:    Given the root of a binary tree, return the sum of values of its deepest leaves.

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
    int deepestLeavesSum(TreeNode* root) {
        int depth = maxDepth(root);
        return getSum(root, depth);
    }
public: 
    int maxDepth (TreeNode* node)
    {
        if (node == NULL) return 0;
        return max(maxDepth(node->left) + 1, maxDepth(node->right) + 1);
    }
public:
    int getSum(TreeNode* root, int level)
    {
        if (root == NULL) return 0;
        if (level == 1) return root->val;
        return getSum(root->left, level-1) + getSum(root->right, level-1);
    }
};