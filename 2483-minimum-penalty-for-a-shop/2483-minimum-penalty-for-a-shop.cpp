class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n= customers.size();
        vector<int> nos,yes;
        nos.push_back(0);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(customers[i]=='N')
                sum++;
            nos.push_back(sum);
        }
        
        sum=0;
        yes.push_back(0);
        for(int i=n-1;i>=0;--i)
        {
            if(customers[i]=='Y')
                sum++;
            yes.push_back(sum);
        }
        reverse(yes.begin(),yes.end());
        int min_val=INT_MAX;
        int min_index=n;
        for(int i=0;i<=n;++i)
        {
            if(yes[i]+nos[i]<min_val)
            {
                min_val=yes[i]+nos[i];
                min_index=i;
            }
        }
        return min_index;
    }
};