/*
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Follow up: Could you do this in one pass?
 */



/*
 * 1->2->3->4->5->NULL n = 2, remove 4
 */

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {

            if (head == NULL)
            {
                return NULL;
            }
            ListNode *fwd = NULL;   /*  Node that is n steps away from the head */
            ListNode *cur = NULL;

            fwd = head;
            cur = head;
            while (fwd != NULL && n >= 0)
            {
                fwd = fwd->next;
                n--;
            }
            if (fwd == NULL && n == 0)
            {
                return head->next;
            }
            while (fwd != NULL)
            {
                fwd = fwd->next;
                cur = cur->next;
            }
            cur->next = cur->next->next;
            return head;

        }
};
