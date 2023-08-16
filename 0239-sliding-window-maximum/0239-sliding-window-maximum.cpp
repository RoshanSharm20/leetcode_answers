class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> nodes;
        int start=0,end=0;
        vector<int> ans;
        while(end<nums.size())
        {
            while(!nodes.empty() && nodes.back()<nums[end])
                nodes.pop_back();
            nodes.push_back(nums[end]);
            if(end-start+1<k)
                end++;
            else
            {
                ans.push_back(nodes.front());
                if(nums[start]==nodes.front())
                    nodes.pop_front();
                start++;
                end++;
            }
        }
        return ans;
    }
};