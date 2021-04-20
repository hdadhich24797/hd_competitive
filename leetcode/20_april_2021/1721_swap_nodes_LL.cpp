#include<iostream>
using namespace std;

/*
 * You are given the head of a linked list, and an integer k.
 *
 * Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
 */

class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            if (head == NULL)
                return NULL;
            ListNode *start = head;
            ListNode *temp1 = head;
            ListNode *temp2 = head;
            int i = 0;
            for (i = 0; i < k - 1; i++)
            {
                temp1 = temp1->next;
            }
            cout<<temp1->val;
            start = temp1;
            while (temp1 != NULL && temp1->next != NULL)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            cout<<temp2->val;
            /* swap temp2 and start */
            int temp = start->val;
            start->val = temp2->val;
            temp2->val = temp;

            return head;

        }
};
