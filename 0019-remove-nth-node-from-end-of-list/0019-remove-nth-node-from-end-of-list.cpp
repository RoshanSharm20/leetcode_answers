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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head->next==NULL)
            return NULL;
        int i=1;
        ListNode *first=head,*second=head;
        while(i<=n)
        {
            first=first->next;
            i++;
        }
        ListNode *prev=second;
        while(first)
        {
            prev=second;
            first=first->next;
            second=second->next;
        }
        if(second==head)
            head=head->next;
        else
            prev->next=second->next;
        
        return head;
    }
};