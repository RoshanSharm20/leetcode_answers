class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        long long int sum =0;
        for(int i=0;i<k;++i)
        {
            if((happiness[i]-(i*1))>0)
                sum += (happiness[i]-(i*1));
        }
        
        // int rsum = 0;
        // for(int i=k;i<happiness.size();++i)
        // {
        //     if(happiness[i]-k>0)
        //         rsum+=(happiness[i]-k);
        // }
        
        return sum;
    }
};