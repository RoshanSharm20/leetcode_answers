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
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
            return head;
        ListNode *less_head = new ListNode(-1);
        ListNode *less_tail = less_head;
        
        
        ListNode *more_head = new ListNode(-1);
        ListNode *more_tail = more_head;
        
        ListNode *curr=head;
        while(curr)
        {
            if(curr->val<x)
            {
                less_tail->next=curr;
                less_tail=less_tail->next;
            }
            else
            {
                more_tail->next=curr;
                more_tail=more_tail->next;
            }
            curr=curr->next;
        }
        
        more_tail->next=NULL;
        less_tail->next=more_head->next;
        return less_head->next;
    }
};