class Solution {
public:
    int min_value(int x)
    {
        if(x%3==0)
            return x/3;
        else if(x%3==1)
        {
            x-=4;
            return (x/3)+2;
        }
        else if(x%3==2)
        {
            x-=2;
            return (x/3)+1;
        }
        return 0;
    }
    int minOperations(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> nodes;
        int count=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==nums[i-1])
                count++;
            else
            {
                nodes.insert({nums[i-1],count});
                count=1;
            }
        }
        nodes.insert({nums[nums.size()-1],count});
        
        int ans=0;
        unordered_map<int,int> values;
        for(auto it:nodes)
        {
            int count = it.second;
            if(count==1)
                return -1;
            if(values.find(count)!=values.end())
            {
                ans+=values[count];   
            }
            else
            {
                int x = min_value(count);
                ans+=x;
                values[count]=x;
            }
        }
        return ans;
    }
};