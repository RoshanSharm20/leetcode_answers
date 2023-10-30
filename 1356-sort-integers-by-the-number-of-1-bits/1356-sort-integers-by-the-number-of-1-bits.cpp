class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr)
    {
       vector<pair<int,int>> p;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            int n = arr[i];
            int count=0;
            while(n>0)
            {
                n=n&(n-1);
                count++;
            }
            p.push_back({count,arr[i]});
        }
        sort(p.begin(),p.end());
        for(auto it : p)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};