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
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ans;
        ListNode *ptr = new ListNode();
        ptr = head;
        while (ptr != NULL)
        {
            int max_val = 0;
            ListNode *temp = new ListNode();
            temp = ptr;
            while (temp != NULL)
            {
                if ((temp->val) > ptr->val)
                {
                    max_val = temp->val;
                    break;
                }
                temp = temp->next;
            }
            ans.push_back(max_val);
            ptr = ptr->next;
        }
        return ans;
    }
};