/*
Problem Title:  Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Problem URL:    https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    private: TreeNode* returnedReference;
    public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverceBoth(original, cloned, target);
        return returnedReference;
    }
    
    private:
    void traverceBoth(TreeNode* originalNode, TreeNode* clonedNode, TreeNode* target)
    {
        if(originalNode == NULL) return;
        if(originalNode == target) {returnedReference = clonedNode; return;}
        traverceBoth(originalNode->left, clonedNode->left, target);
        traverceBoth(originalNode->right, clonedNode->right, target);
    }
    
};