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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int count1=0;
        ListNode *temp=head;
        while(temp && count1<k)
        {
            temp=temp->next;
            count1++;
        }
        if(count1==k)
        {
            int count=0;
            ListNode *curr=head,*prev=NULL,*nextnode=NULL;
            while(curr && count<k)
            {
                nextnode = curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;
                count++;
            }
            if(nextnode!=NULL)
            {
                ListNode *resthead=reverseKGroup(nextnode,k);
                head->next=resthead;
            }
            return prev;
        }
        return head;
    }
};