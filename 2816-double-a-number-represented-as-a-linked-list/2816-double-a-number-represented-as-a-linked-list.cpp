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
    ListNode* reverse_list(ListNode* head)
    {
        ListNode *prev=NULL,*curr=head,*nxt=NULL;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) 
    {
        head = reverse_list(head);
        int carry=0;
        ListNode *ptr=head;
        ListNode *dummy = ptr;
        while(ptr)
        {
            int value = (2*ptr->val)+carry;
            int digit = value%10;
            carry = value/10;
            ptr->val= digit;
            dummy=ptr;
            ptr=ptr->next;
        }
        
        if(carry)
        {
            ListNode *newnode = new ListNode(carry);
            dummy->next=newnode;
        }
        
        head = reverse_list(head);
        return head;
    }
};