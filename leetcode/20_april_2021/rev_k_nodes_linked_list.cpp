#include<iostream.cpp>
using namespace std;
/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 */

/*
 * eg
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 */

/*  Solve extreme right first as it was difficult to manage head if we start from the left
 */

class Solution {
    public:
            
            ListNode* reverseKGroup(ListNode* head, int k) {
                ListNode *temp = head;
                while (temp != NULL && k >= 0)
                {
                    temp = temp->next;
                }
                if (k < 0)
                {
                    /*  No need to rev the list */
                    return head;
                }
                /*  Go to the right first   */
                ListNode *prv = reverseKGroup(temp, k);
                while (head != temp)
                {
                    /*  rev */
                    ListNode *nxt = head->next;
                    head->next = prv;

                    /*  move pointers ahead */
                    prv = head;
                    head = nxt;
                }
                return prv;
            }
};
