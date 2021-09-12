/*
Problem Title:  Add Two Numbers
Problem URL:    https://leetcode.com/problems/add-two-numbers/
Description:    You are given two non-empty linked lists representing two non-negative integers. 
                The digits are stored in reverse order, and each of their nodes contains a single digit. 
                Add the two numbers and return the sum as a linked list.
                You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Difficulty: Medium
Language: C++
Category: Algorithms
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = l1; ListNode* previousL1;
        int carry=0, sum=0;
        
        while(l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                ListNode* newNode = new ListNode(); 
                previousL1->next=newNode; l1 = newNode;
            }
            if (l2 != NULL)
            {
                sum = (l1->val + l2->val + carry);
                l2 = l2->next;
            }
            else
                sum = (l1->val + carry);
            carry = sum / 10;
            sum %= 10;
            l1->val = sum;
            previousL1 = l1;
            l1 = l1->next;
        }
        
        if (carry != 0) 
        {
            ListNode* lastDigit = new ListNode(carry); 
            previousL1->next=lastDigit;
        }
        return result;
    }
};
