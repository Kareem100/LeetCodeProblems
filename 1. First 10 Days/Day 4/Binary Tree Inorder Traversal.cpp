/*
Problem Title:  Binary Tree Inorder Traversal
Problem URL:    https://leetcode.com/problems/binary-tree-inorder-traversal/
Description:    Given the root of a binary tree, return the inorder traversal of its nodes' values.
Difficulty: Easy
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
    vector<int> nodesValues;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return nodesValues;
    }
    private:
    void traverse (TreeNode* root)
    {
        if (root == NULL) return;
        traverse(root->left);
        nodesValues.push_back(root->val);
        traverse(root->right);
    }
};