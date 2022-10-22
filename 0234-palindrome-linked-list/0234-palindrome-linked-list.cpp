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
    bool isPalindrome(ListNode* head) 
    {
        ListNode *fast = head,*slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *headB=NULL;
        if(fast==NULL)
            headB=slow;
        else
            headB=slow->next;
        // slow->next=NULL;
        ListNode *prev=NULL,*curr=headB;
        while(curr)
        {
            ListNode *nextnode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        headB=prev;
        while(headB)
        {
            if(head->val!=headB->val)
                return false;
            
            head=head->next;
            headB=headB->next;
        }
        return true;
    }
    
};