class Solution {
public:
    int tribonacci(int n) 
    {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        int a = 0,b=1,c=1,d=0;
        while(n-2>0)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            n--;
        }
        return d;
    }
};