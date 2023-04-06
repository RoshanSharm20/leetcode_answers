class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int i=0;
        vector<int> bitsa(31,0),bitsb(31,0);
        while(a)
        {
            if(a&1)
                bitsa[i]++;
            a>>=1;
            i++;
        }
        i=0;
        while(b)
        {
            if(b&1)
                bitsb[i]++;
            b>>=1;
            i++;
        }
        i=0;
        int count=0;
        while(i<31)
        {
            if(c&1)
            {
                if((bitsa[i]==0)&&(bitsb[i]==0))
                    count++;
            }
            else
            {
                if((bitsa[i]==1)&&(bitsb[i]==1))
                    count+=2;
                else if((bitsa[i]==0 && bitsb[i]==1) || (bitsa[i]==1 && bitsb[i]==0))
                    count++;
            }
            c>>=1;
            i++;
        }
        return count;
    }
};