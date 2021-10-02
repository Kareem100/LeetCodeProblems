/*
Problem Title:  Construct Binary Search Tree from Preorder Traversal
Problem URL:    https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Description:    Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
                construct the tree and return its root.
                It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
                A binary search tree is a binary tree where for every node, 
                any descendant of Node.left has a value strictly less than Node.val, 
                and any descendant of Node.right has a value strictly greater than Node.val.
                A preorder traversal of a binary tree displays the value of the node first, 
                then traverses Node.left, then traverses Node.right.

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for (int i = 1; i < preorder.size(); ++i)
            DFS(root, preorder[i]);
        
        return root;
    }
    
    void DFS(TreeNode* root, int val) {
        if (root == NULL) return;
        
        if (val < root->val) {
            if (root->left == NULL) {
                root->left = new TreeNode(val);
                return;
            }
            DFS(root->left, val);
        }
        
        else {
            if (root->right == NULL) {
                root->right = new TreeNode(val);
                return;
            }
            DFS(root->right, val);
        }
    }
    
};