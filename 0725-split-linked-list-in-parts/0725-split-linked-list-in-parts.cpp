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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int count=0;
        vector<ListNode*> vect;
        ListNode *ptr=head,*curr=head;
        while(ptr)
        {
            count++;
            ptr=ptr->next;
        }
        
        cout<<count<<endl;
        int div_val=count/k,div_extra=count%k;
        
        ptr=NULL;
        while(k>0)
        {
            ListNode* dummy=new ListNode(-1);
            dummy->next=curr;
            int in_count=0;
            while(curr && in_count<div_val)
            {
                ptr=curr;
                curr=curr->next;
                in_count++;
            }
            
            if(div_extra>0)
            {
                ptr=curr;
                curr=curr->next;
                div_extra--;
            }
            if(ptr)
                ptr->next=NULL;
            k--;
            vect.push_back(dummy->next);
        }
        return vect;
    }
};