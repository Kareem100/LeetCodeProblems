/*
Problem Title: Merge Two Sorted Lists
Problem URL: https://leetcode.com/problems/merge-two-sorted-lists/
Description: Merge two sorted linked lists and return it as a sorted list. 
             The list should be made by splicing together the nodes of the first two lists.
Difficulty: Easy
Language: C++
Category: Algorithms
*/
/*****************************************************************/
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
/*****************************************************************/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *sortedList, *temp;
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        if (l1->val < l2->val) {sortedList = l1; l1 = l1->next;}
        else {sortedList = l2; l2 = l2->next;}
        temp = sortedList;
        
        while (true)
            if (l1 == NULL) {temp->next = l2; break;}
            else if (l2 == NULL) {temp->next = l1; break;}
            else if (l1->val < l2->val)
            {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else 
            {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        
        return sortedList;
    }
};