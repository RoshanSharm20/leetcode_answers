class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>> nodes(n,vector<int>(m,0));
        for(int i=0;i<m;++i)
        {
            int count=0;
            for(int j=0;j<n;++j)
            {
                if(matrix[j][i]==1)
                {
                    count++;
                    nodes[j][i]=count;
                }
                else
                {
                    count=0;
                }
            }
        }
        int max_value = 0;
        for(auto it:nodes)
        {
            sort(it.rbegin(),it.rend());
            for(int i=0;i<m;++i)
            {
                int value = it[i]*(i+1);
                max_value = max(max_value,value);
            }
        }
        
        return max_value;
    }
};