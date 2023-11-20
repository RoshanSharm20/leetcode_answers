class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int sum=0;
        int support=0;
        for(int i=garbage.size()-1;i>=0;--i)
        {
            int count=0;
            for(int j=0;j<garbage[i].size();++j)
            {
                if(garbage[i][j]=='M')
                    count++;
            }
            if(count>0)
            {
                sum+=count;
                support=1;
            }
            if(count>0 || support==1)
                if(i-1>=0)
                    sum+=travel[i-1];  ;  
        }
        support=0;
        for(int i=garbage.size()-1;i>=0;--i)
        {
            int count=0;
            // int support=0;
            for(int j=0;j<garbage[i].size();++j)
            {
                if(garbage[i][j]=='G')
                    count++;
            }
            if(count>0)
            {
                sum+=count;
                support=1;
            }
            if(count>0 || support==1)
                if(i-1>=0)
                    sum+=travel[i-1];   
        }
        support=0;
        for(int i=garbage.size()-1;i>=0;--i)
        {
            int count=0;
            // int support=0;
            for(int j=0;j<garbage[i].size();++j)
            {
                if(garbage[i][j]=='P')
                    count++;
            }
            if(count>0)
            {
                sum+=count;
                support=1;
            }
            if(count>0 || support==1)
                if(i-1>=0)
                    sum+=travel[i-1];  
        }
        return sum;
    }
};