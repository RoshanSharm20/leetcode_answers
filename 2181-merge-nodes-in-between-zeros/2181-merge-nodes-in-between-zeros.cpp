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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* dummy=new ListNode();
        ListNode*head1=dummy;
        int sum=0;
        if(head==NULL)
            return NULL;
        else
        {
            ListNode* ptr =head->next;
            while(ptr!=NULL)
            {
                sum+=ptr->val;
                if(ptr->val==0)
                {
                    ListNode* newnode=new ListNode(sum);
                    head1->next=newnode;
                    head1=head1->next;
                    sum=0;
                }
                ptr=ptr->next;
            }
        }
        return dummy->next;
    }
};