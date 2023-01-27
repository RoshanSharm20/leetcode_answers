class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();++i)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<grid[0].size();++j)
                {
                    if(grid[i][j]==0)
                        grid[i][j]=1;
                    else
                        grid[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<grid[0].size();++i)
        {
            int count_ones=0,count_zeroes=0;
            for(int j=0;j<grid.size();++j)
            {
                if(grid[j][i]==0)
                    count_zeroes++;
                else
                    count_ones++;
            }
            
            if(count_zeroes>count_ones)
            {
              for(int j=0;j<grid.size();++j)
                {
                    if(grid[j][i]==0)
                        grid[j][i]=1;
                    else
                        grid[j][i]=0;
                }  
            }
        }
        
        int total_sum=0;
        int n=grid[0].size()-1;
        for(int i=0;i<grid.size();++i)
        {
            int sum=0;
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                    sum+=pow(2,(n-j));
            }
            total_sum+=sum;
        }
        return total_sum;
    }
};