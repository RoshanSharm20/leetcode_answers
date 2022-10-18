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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        set<int> s;
        for (auto it : nums)
            s.insert(it);
        int count = 0, ans = 0;
        while (head)
        {
            if (s.count(head->val) != 0)
                count++;
            else
            {
                if (count)
                    ans++;
                count = 0;
            }
            head = head->next;
        }
        if (count)
            ans++;
        return ans;
    }
};