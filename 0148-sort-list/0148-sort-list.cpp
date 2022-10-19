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
    ListNode* sortList(ListNode* head) 
    {
        vector<int> ans;
        while(head)
        {
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        ListNode *dummy=new ListNode(-1);
        ListNode *ptr=dummy;
        for(int i=0;i<ans.size();++i)
        {
            ListNode *temp = new ListNode(ans[i]);
            ptr->next=temp;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};