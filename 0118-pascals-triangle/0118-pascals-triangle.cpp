class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        vector<int> v(1,1);
        ans.push_back(v);
        for(int i=1;i<numRows;++i)
        {
            vector<int> v1(i+1,1);
            for(int j=1;j<i;++j)
            {
                v1[j]=v[j-1]+v[j];
            }
            v=v1;
            ans.push_back(v1);
        }
        return ans;
    }
};