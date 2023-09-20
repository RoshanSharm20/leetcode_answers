class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();
        
        unordered_map<int,int> nodes;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
            nodes[sum]=i;
        }
        
        if(sum<x)
            return -1;
        
        sum-=x;
        int val=0,longest=0;
        for(int i=0;i<n;++i)
        {
            val+=nums[i];
            
            if(val==sum)
                longest=(i+1);
            else if(nodes.find(val-sum)!=nodes.end())
            {
                longest=max(longest,i-nodes[val-sum]);
            }
        }
        
        return longest==0?(sum==0?n:-1):n-longest;
    }
};