class Solution {
public:
    int maximumXOR(vector<int>& nums) 
    {
        vector<bool> present(32,false);
        for(auto it:nums)
        {
            int index = 0;
            while(it>0)
            {
                if(it&1==1)
                    present[index]=true;
                index++;
                it/=2;
            }
        }
        
        int ans=0;
        long long int pow = 1;
        for(int i=0;i<32;++i)
        {
            if(present[i])
                ans+=pow;
            pow*=2;
        }
        return ans;
    }
};