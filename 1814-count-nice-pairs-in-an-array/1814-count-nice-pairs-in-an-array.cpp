class Solution {
public:
    int mod = 1e9+7;
    int rev(int n)
    {
        int num=0;
        while(n>0)
        {
            int rem = n%10;
            num = num*10+rem;
            n/=10;
        }
        return num;
    }
    int countNicePairs(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();++i)
        {
            nums[i] = nums[i]-rev(nums[i]);
        }
        int count=0;
        unordered_map<int,int> nodes;
        for(auto it:nums)
        {
            if(nodes.find(it)==nodes.end())
            {
                nodes[it]=1;
                cout<<it<<endl;
            }
            else
            {
                count = (count + nodes[it])%mod;
                nodes[it]+=1;
            }
        }
        return count;
    }
};