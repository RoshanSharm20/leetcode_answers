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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> ans(2,-1);
        vector<int> count;
        vector<int> index;
        while(head)
        {
            count.push_back(head->val);
            head=head->next;
        }
        if(count.size()<=3)
            return ans;
        else
        {
            for(int i=1;i<=count.size()-2;++i)
            {
                if(((count[i]>count[i-1])&&(count[i]>count[i+1]))||((count[i]<count[i-1])&&(count[i]<count[i+1])))
                index.push_back(i+1);    
            }
            if(index.size()<2)
                return ans;
            else if(index.size()==2)
            {
                ans[0]=index[1]-index[0];
                ans[1]=index[1]-index[0];
                return ans;
            }
            else
            {
                int min_val=INT_MAX;
                for(int i=1;i<index.size();++i)
                    min_val=min(min_val,index[i]-index[i-1]);
                ans[0]=min_val;
                ans[1]=index[index.size()-1]-index[0];
                return ans;
            }
        }
        return ans;
    }
};