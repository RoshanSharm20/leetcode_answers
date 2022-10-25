class Solution {
public:
    double myPow(double x, int n) 
    {
        double pow=1;
        if(x==1)
            return 1;
        if(n<0)
            x=1/x;
        long nums=labs(n);
        while(nums)
        {
            if((nums & 1)!=0)
                pow*=x;
            x*=x;
            nums>>=1;
        }
        return pow;
    }
};