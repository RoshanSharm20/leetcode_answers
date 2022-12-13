class Solution {
public:
    void solution(vector<vector<int>>& matrix,int row,int col,int asf,int& min_val)
    {
        if(col<0 || col==matrix.size())
            return;
        if(row==matrix.size()-1)
        {
            asf+=matrix[row][col];
            min_val=min(min_val,asf);
            return;
        }
        asf+=matrix[row][col];
        solution(matrix,row+1,col-1,asf,min_val);
        solution(matrix,row+1,col,asf,min_val);
        solution(matrix,row+1,col+1,asf,min_val);
    }
    int minFallingPathSum(vector<vector<int>>& v) 
    {
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        int ans=INT_MAX;
        int m=v.size();
        int n=v[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j] = v[i][j];
                }
                else{
                    dp[i][j] = v[i][j];
                    int mn=INT_MAX;
                    if((j-1)>=0){
                        mn = min(mn,dp[i-1][j-1]);
                    }
                    if((j+1)<n){
                        mn = min(mn,dp[i-1][j+1]);
                    }
                    mn = min(mn,dp[i-1][j]);
                    dp[i][j]+=mn;
                }
                if(i==m-1){
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};