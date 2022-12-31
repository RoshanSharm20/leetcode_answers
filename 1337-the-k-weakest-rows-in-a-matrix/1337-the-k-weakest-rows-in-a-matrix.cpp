class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>> values;
        vector<int> ans;
        int i=0;
        for(auto vec : mat)
        {
            int n = count(vec.begin(),vec.end(),1);
            values.push_back({n,i});
            i++;
        }
        sort(values.begin(),values.end());
        for(int i=0;i<k;++i)
        {
            int n1=values[i].second;
            ans.push_back(n1);
        }
        return ans;
    }
};