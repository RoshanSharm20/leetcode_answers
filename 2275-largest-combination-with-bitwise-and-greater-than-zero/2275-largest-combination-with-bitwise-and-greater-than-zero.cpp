class Solution {
public:
    int largestCombination(vector<int>& c) 
    {
        //basically need to find the frequency of max frequency of ones at a particular index
        
        //the max frequency of ones will tell the largest combination size as they do not want the combination with max value,only the largest non zero combination
        
        vector<int> index(31,0);
        for(int i=0;i<c.size();++i)
        {
            int x = c[i];
            for(int j=0;j<=30;++j)
            {
                if(x & (1<<j))
                    index[j]++;
            }
        }
        
        int max_size = 1;
        for(int i=0;i<=30;++i)
        {
            max_size = max(max_size,index[i]);
        }
        return max_size;
    }
};