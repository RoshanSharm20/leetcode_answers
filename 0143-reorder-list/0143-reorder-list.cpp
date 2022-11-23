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
    void reorderList(ListNode* head) 
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *curr;
        while(fast!=NULL && fast->next!=NULL)
        {
            curr=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *headB;
        if(fast!=NULL)
        {
            headB=slow->next;
            slow->next=NULL;
        }
        else
        {
            headB=slow;
            curr->next=NULL;
        }
        
        ListNode *prev=NULL;
        curr=headB;
        
        while(curr)
        {
            ListNode *nes = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nes;
        }
        headB=prev;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *nesA,*nesB;
        while(head && headB)
        {
            nesA=head->next;
            nesB=headB->next;
            head->next=headB;
            headB->next=nesA;
            head=nesA;
            headB=nesB;
        }
    }
};