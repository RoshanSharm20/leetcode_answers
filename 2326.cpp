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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        ListNode *ptr = new ListNode();
        ptr = head;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int top = 0, left = 0, bottom = m - 1, right = n - 1;
        while ((top <= bottom) && (left <= right))
        {
            for (int i = left; i <= right && ptr; ++i)
            {

                ans[top][i] = ptr->val;
                ptr = ptr->next;
            }
            top++;
            for (int i = top; i <= bottom && ptr; ++i)
            {

                ans[i][right] = ptr->val;

                ptr = ptr->next;
            }
            right--;

            for (int i = right; i >= left && ptr; --i)
            {

                ans[bottom][i] = ptr->val;
                ptr = ptr->next;
            }
            bottom--;

            for (int i = bottom; i >= top && ptr; --i)
            {

                ans[i][left] = ptr->val;
                ptr = ptr->next;
            }
            left++;
        }
        return ans;
    }
};