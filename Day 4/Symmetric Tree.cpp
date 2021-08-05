/*
Problem Title:  Symmetric Tree
Problem URL:    https://leetcode.com/problems/symmetric-tree/
Description:    Given the root of a binary tree, 
                check whether it is a mirror of itself (i.e., symmetric around its center).
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
private: vector<int>moga;
private: int primal;
public:
    bool isSymmetric(TreeNode* root) {
        primal = -1;
        traverseLeft(root->left);
        primal = -1;
        traverseRight(root->right);
        int k = moga.size()/2;
        if (moga.size()%2==0)
        {
            for (int i = 0; i < moga.size() / 2; ++i, ++k)
                if (moga[i] != moga[k])
                    return false;
        }
        else return false;
        return true;
    }
private:
    void traverseLeft(TreeNode* root)
    {
        if(root == NULL) {moga.push_back(primal); return;} 
        primal--;
        traverseLeft(root->left);
        moga.push_back(root->val);
        traverseLeft(root->right);
    }
private:
    void traverseRight(TreeNode* root)
    {
        if(root == NULL) {moga.push_back(primal); return;} 
        primal--;
        traverseRight(root->right);
        moga.push_back(root->val);
        traverseRight(root->left);
    }
};