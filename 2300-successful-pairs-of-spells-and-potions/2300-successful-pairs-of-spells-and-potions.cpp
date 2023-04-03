class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto it:spells)
        {
            int start = 0,end=potions.size()-1,a=-1;
            while(start<=end)
            {
                int mid = (start+end)/2;
                if((long long)it*potions[mid]>=success)
                {
                    a=mid;
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            if(a==-1)
                ans.push_back(0);
            else
                ans.push_back(potions.size()-a);
        }
        return ans;
    }
};