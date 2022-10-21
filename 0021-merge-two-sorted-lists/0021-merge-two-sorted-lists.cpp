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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        // ListNode *ptr1=list1,*ptr2=list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *head=dummy;
        while(list1 && list2)
        {
            if(list1->val <=list2->val)
            {
                int x=list1->val;
                ListNode *newnode = new ListNode(x);
                head->next=newnode;
                head=head->next;
                list1=list1->next;
            }
            else
            {
                int x= list2->val;
                ListNode *newnode = new ListNode(x);
                head->next=newnode;
                head=head->next;
                list2=list2->next;
            }
        }
        while(list1)
        {
            int x = list1->val;
            ListNode *newnode = new ListNode(x);
            head->next=newnode;
            head=head->next;
            list1=list1->next;
        }
        while(list2)
        {
            int x = list2->val;
            ListNode *newnode = new ListNode(x);
            head->next=newnode;
            head=head->next;
            list2=list2->next;
        }
        return dummy->next;
    }
};