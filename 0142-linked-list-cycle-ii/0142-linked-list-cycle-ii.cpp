/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        unordered_set<ListNode*> ans;
        while(head)
        {
            if(ans.find(head)!=ans.end())
                return head;
            ans.insert(head);
            head=head->next;
        }
        return NULL;
    }
};