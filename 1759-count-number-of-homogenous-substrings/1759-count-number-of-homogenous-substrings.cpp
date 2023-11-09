class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) 
    {
        int start = 0;
        long long count=0;
        for(int i=1;i<s.size();++i)
        {
            if(s[i]!=s[i-1])
            {
                long long x = i-start;
                long long value = ((x*(x+1)%mod)/2)%mod;
                count = (count+value)%mod;
                start=i;
            }
            else
            {
                continue;
            }
        }
        
        long long x = s.size()-start;
        long long value = ((x*(x+1)%mod)/2)%mod;
        count = (count+value)%mod;
        return count;
    }
};