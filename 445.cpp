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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = l1;
        vector<int> v1;
        while (ptr != NULL)
        {
            v1.push_back(ptr->val);
            ptr = ptr->next;
        }
        ListNode *ptr2 = l2;
        vector<int> v2;
        while (ptr2 != NULL)
        {
            v2.push_back(ptr2->val);
            ptr2 = ptr2->next;
        }
        int i = v1.size() - 1, j = v2.size() - 1;
        int carry = 0;
        ListNode *head = NULL;
        while (i >= 0 && j >= 0)
        {
            int sum = v1[i] + v2[j] + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(digit);

            temp->next = head;
            head = temp;
            i--;
            j--;
        }
        while (i >= 0)
        {
            int sum = v1[i] + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(digit);
            temp->next = head;
            head = temp;
            i--;
        }
        while (j >= 0)
        {
            int sum = v2[j] + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(digit);
            temp->next = head;
            head = temp;
            j--;
        }
        if (carry)
        {
            ListNode *temp = new ListNode(1);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};