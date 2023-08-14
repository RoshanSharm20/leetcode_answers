class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> nodes;
        for(int i=0;i<nums.size();++i)
        {
            nodes.push(nums[i]);
            if(nodes.size()>k)
                nodes.pop();
        }
        return nodes.top();
    }
};