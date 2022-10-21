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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        vector<int> v1;
        vector<int> v2;
        while(l1)
        {
            int x = l1->val;
            v1.push_back(x);
            l1=l1->next;
        }
        while(l2)
        {
            int x=l2->val;
            v2.push_back(x);
            l2=l2->next;
        }
        // reverse(v1.begin(),v1.end());
        // reverse(v2.begin(),v2.end());
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int carry=0;
        int i=0,j=0;
        while(i<v1.size() && j<v2.size())
        {
            int sum = v1[i] + v2[j] + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode *newnode = new ListNode(digit);
            head->next=newnode;
            head=head->next;
            i++;
            j++;
        }
        
        while(i<v1.size())
        {
            int sum = v1[i] + carry;
            int digit = sum%10;
            carry=sum/10;
            ListNode *newnode = new ListNode(digit);
            head->next=newnode;
            head=head->next;
            i++;
        }
        
        while(j<v2.size())
        {
            int sum = v2[j] + carry;
            int digit = sum%10;
            carry=sum/10;
            ListNode *newnode = new ListNode(digit);
            head->next=newnode;
            head=head->next;
            j++;
        }
        
        if(carry)
        {
            ListNode *newnode = new ListNode(carry);
            head->next=newnode;
            head=head->next;
        }
        return dummy->next;
        
        // ListNode *headMain = dummy->next;
        // ListNode *prev=NULL,*curr=headMain;
        // while(curr)
        // {
        //     ListNode *nextnode = curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nextnode;
        // }
        // return prev;
    }
};