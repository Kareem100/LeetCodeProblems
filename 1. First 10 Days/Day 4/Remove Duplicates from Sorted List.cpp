/*
Problem Title:  Remove Duplicates from Sorted List
Problem URL:    https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Description:    Given the head of a sorted linked list, 
                delete all duplicates such that each element appears only once. 
                Return the linked list sorted as well.
Difficulty: Easy
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* origin = head;
        ListNode* temp = NULL; if (origin != NULL) temp = head->next;
        while(temp!=NULL)
        {
            if (head->val != temp->val)
            {
                head->next = temp;
                head = temp;
            }
            temp = temp->next;
        }
        if (origin != NULL) head->next = NULL;
        return origin;
    }
};