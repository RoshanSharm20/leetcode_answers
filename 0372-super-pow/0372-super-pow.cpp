class Solution {
public:
    int superPow(int a, vector<int>& b) 
    {
        long long int m = 1140;
        long long int mod = 1337;
        long long int power = 0;
        reverse(b.begin(),b.end());
        long long int x = 1;
        for(int i=0;i<b.size();++i)
        {
            power = (power + b[i]*x)%m;
            x=(x*10)%m;
        }
        long long int ans = 1;
        while(power)
        {
            if(power&1)
                ans = (ans*1LL*a)%mod;
            a = (a*1LL*a)%mod;
            power>>=1;
        }
        return ans;
    }
};