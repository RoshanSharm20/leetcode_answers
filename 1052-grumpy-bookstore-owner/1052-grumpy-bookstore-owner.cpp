class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int sat_count=0;
        for(int i=0;i<customers.size();++i)
            if(grumpy[i]==0)
                sat_count+=customers[i];
        int i=0,j=0,ans=0,curr=0;
        while(j<customers.size())
        {
            if(grumpy[j]==1)
                curr+=customers[j];
            if(j-i+1==minutes)
            {
                ans=max(curr,ans);
                if(grumpy[i] == 1)
                curr-=customers[i];
                i++;
            }
            j++;
        }
        sat_count+=ans;
        return sat_count;
    }
};