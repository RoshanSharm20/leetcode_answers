/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        map<ListNode *, int> m;
        ListNode *temp = headA;
        while (temp)
        {
            m[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while (temp)
        {
            if (m.find(temp) != m.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};