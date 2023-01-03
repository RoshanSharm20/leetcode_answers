class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        vector<bool> cols(strs[0].size(),true);
        for(int i=1;i<strs.size();++i)
        {
            for(int j=0;j<strs[i].size();++j)
            {
                if(strs[i][j]<strs[i-1][j])
                    cols[j]=false;
            }
        }
        int count=0;
        for(int i=0;i<cols.size();++i)
        {
            if(cols[i]==false)
                count++;
        }
        return count;
    }
};