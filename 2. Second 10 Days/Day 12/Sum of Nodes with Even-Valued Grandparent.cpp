/*
Problem Title:  Sum of Nodes with Even-Valued Grandparent
Problem URL:    https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
Description:    Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. 
                If there are no nodes with an even-valued grandparent, return 0.
                A grandparent of a node is the parent of its parent if it exists.

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
    int sumEvenGrandparent(TreeNode* root) {
        return getSum(root, NULL, NULL);
    }
    
    public:
        int getSum(TreeNode* node, TreeNode* parent, TreeNode* grandParent)
        {
            if (node == NULL) return 0;
            if (grandParent != NULL && grandParent->val%2==0)
                return node->val + getSum(node->left, node, parent) + getSum(node->right, node, parent);
            return getSum(node->left, node, parent) + getSum(node->right, node, parent);
        }
    
};