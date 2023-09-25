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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode *curr=head,*next_node=head->next;
        while(curr && next_node)
        {
            int gcd_val = __gcd(curr->val,next_node->val);
            ListNode *newNode = new ListNode(gcd_val);
            curr->next=newNode;
            newNode->next=next_node;
            curr=next_node;
            next_node=next_node->next;
        }
        return head;
    }
};