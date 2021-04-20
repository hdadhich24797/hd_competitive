#include<iostream>
using namespace std;

/*
 * You are given two linked lists: list1 and list2 of sizes n and m respectively.
 *
 * Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
 *
 */

class Solution {
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode *temp1 = list1;
            ListNode *temp2 = list1;
            int i = 0;
            for (i = 0; i < a - 1; i++)
            {
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            for (; i < b; i++)
            {
                temp2 = temp2->next;
            }
            temp1->next = list2;

            while (list2 != NULL && list2->next != NULL)
            {
                list2 = list2->next;
            }
            list2->next = temp2;

            return list1;
        }
};
