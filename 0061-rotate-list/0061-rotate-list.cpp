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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
            return head;     
        vector<int> v;
        ListNode *ptr=head;
        int count=0;
        while(ptr)
        {
            count++;
            int x=ptr->val;
            v.push_back(x);
            ptr=ptr->next;
        }
        k=k%count;
        k=count-k;
        // cout<<k<<endl;
        // return NULL;
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
        reverse(v.begin(),v.end());
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        for(int i=0;i<v.size();++i)
        {
            ListNode *newnode=new ListNode(v[i]);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};