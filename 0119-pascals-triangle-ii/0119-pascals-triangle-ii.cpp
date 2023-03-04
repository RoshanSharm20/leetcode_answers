class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> ans = {1};
        for(int i=0;i<rowIndex;++i)
        {
            vector<int> temp = {1};
            for(int j=1;j<ans.size();++j)
            {
                temp.push_back(ans[j]+ans[j-1]);
            }
            temp.push_back(1);
            ans=temp;
        }
        return ans;
    }
};