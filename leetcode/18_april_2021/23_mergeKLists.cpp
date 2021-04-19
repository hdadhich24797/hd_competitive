class Solution {
    public:

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int n = lists.size();
            if (n == 0)
            {
                return NULL;
            }
            ListNode *head = NULL;
            ListNode *temp = NULL;
            ListNode *temp1 = NULL;
            for (int i = 0; i < n; i++)
            {
                temp = lists[i];
                while (temp != NULL)
                {
                    temp1 = head;
                    ListNode *newNode = new ListNode(temp->val);
                    if (head == NULL)
                    {
                        head = newNode;
                    }
                    else
                    {
                        if (temp->val < head->val)
                        {
                            cout<<"here1"<<endl;
                            temp1 = head;
                            head = newNode;
                            head->next = temp1;
                        }
                        else
                        {
                            while(temp1->next != NULL && temp->val > temp1->next->val)
                            {
                                temp1 = temp1->next;
                            }
                            if (temp1->next != NULL)
                            {
                                newNode->next = temp1->next;
                                temp1->next = newNode;
                            }
                            else
                            {
                                temp1->next = newNode;
                            }

                        }
                    }

                    temp = temp->next;
                }
            }
            return head;
        }
};

