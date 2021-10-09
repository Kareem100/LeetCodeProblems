/*
Problem Title:  Recover a Tree From Preorder Traversal
Problem URL:    https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

Description:    We run a preorder depth-first search (DFS) on the root of a binary tree.
                At each node in this traversal, we output D dashes (where D is the depth of this node), 
                then we output the value of this node. 
                If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
                If a node has only one child, that child is guaranteed to be the left child.
                Given the output traversal of this traversal, recover the tree and return its root.

Difficulty: Hard
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
    string traversal;
    int idx = 0;
    
    int getNextValue() {
        
        int value=0;
        for (; idx < traversal.size(); ++idx) 
        {
            if (traversal[idx] == '-') break;
            value = value*10 + (traversal[idx] - '0');
        }
        
        return value;
    }
    
    int getNextLevel() {
        
        int count = 0;
        for (; idx < traversal.size(); ++idx, count++)
            if (traversal[idx] != '-') break;

        return count;
    }
    
    TreeNode* recoverTree(TreeNode* node, int depth) {
       
        int level = getNextLevel();
        if (level != depth) {
            idx -= level;
            return NULL;
        }
        
        int value = getNextValue();
        node = new TreeNode(value);
        
        node->left = recoverTree(node->left, depth+1);
        node->right = recoverTree(node->right, depth+1);
        
        return node;
    }
    
public:
    TreeNode* recoverFromPreorder(string s) {
        
        traversal = s;
        
        TreeNode* root;
        root = recoverTree(root, 0);
        
        return root;
    }
};