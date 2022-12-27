class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int max_count = 0;
        vector<int> rem;
        for(int i=0;i<rocks.size();++i)
        {
            rem.push_back(capacity[i]-rocks[i]);
        }
        
        sort(rem.begin(),rem.end());
        int i = 0;
        while(i<rem.size() && additionalRocks>0)
        {
            if(rem[i]==0)
            {
                max_count++;
                i++;
            }
            else if(additionalRocks>=rem[i])
            {
                max_count++;
                additionalRocks-=rem[i];
                i++;
            }
            else
                break;
        }
        return max_count;
    }
};