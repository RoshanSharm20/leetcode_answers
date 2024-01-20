class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int mod=1e9+7,n=arr.size();
        stack<int> s1,s2;
        vector<int> next_small(n),pre_small(n);
        
        for(int i=0;i<n;++i)
        {
            next_small[i]=n-i-1;
            pre_small[i]=i;
        }
        
        for(int i=0;i<n;++i)
        {
          while(!s1.empty() && arr[s1.top()]>arr[i])
          {
              next_small[s1.top()]=i-s1.top()-1;
              s1.pop();
          }
          s1.push(i);
        }
        
        for(int i=n-1;i>=0;--i)
        {
            while(!s2.empty() && arr[s2.top()]>=arr[i])
            {
                pre_small[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        
        long long int ans=0;
        for(int i=0;i<n;++i)
        {
            long long int val = arr[i]%mod;
            val = (val%mod * (next_small[i]+1)%mod)%mod;
            val = (val%mod * (pre_small[i]+1)%mod)%mod;
            
            ans = (ans%mod + val%mod)%mod;
        }
        
        return ans;
    }
};