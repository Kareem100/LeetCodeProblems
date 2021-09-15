/*
Problem Title:  Binary Search Tree to Greater Sum Tree
Problem URL:    https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Description:    Given the root of a Binary Search Tree (BST), 
                convert it to a Greater Tree such that every key of the original BST 
                is changed to the original key plus sum of all keys greater than the original key in BST.
                As a reminder, a binary search tree is a tree that satisfies these constraints:
                The left subtree of a node contains only nodes with keys less than the node's key.
                The right subtree of a node contains only nodes with keys greater than the node's key.
                Both the left and right subtrees must also be binary search trees.

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
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }

private: int sum = 0;
public:
    void solve(TreeNode* root)
    {
        if (root == NULL) return;
        solve(root->right);
        sum += root->val;
        root->val = sum;
        solve(root->left);
    }
};