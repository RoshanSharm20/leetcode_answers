class Solution {
public:
    long long power(int a,long long b,int mod)
    {
        if(b==0)
            return 1;
        long long x = power(a,b/2,mod);
        if(b%2==0)
            return ((x*x)%mod);
        else
            return (((a*x)%mod)*x)%mod;
    }
    int countGoodNumbers(long long n) 
    {
        int mod = 1e9+7;
        return ((power(5,(n+1)/2,mod)*power(4,n/2,mod))%mod);
    }
};
