class Solution {
public:
    int minFlips(string target) 
    {
        int count=0;
        int start=0;
        for(int i=1;i<target.size();++i)
        {
            if(target[i]==target[start])
                continue;
            else
            {
                start=i;
                count++;
            }
        }
        if(count==0)
            return 0;
        int n=target.size();
        if((target[0]=='0' && target[n-1]=='0'))
        {
            return count;
        }
        if((target[0]=='1' && target[n-1]=='0')||(target[0]=='1' && target[n-1]=='1'))
        {
            count++;
            return count;
        }
        else if(target[0]=='0' && target[n-1]=='1')
            return count;
        return count;
    }
};