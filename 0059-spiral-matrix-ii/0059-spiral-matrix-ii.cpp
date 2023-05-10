class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> v(n,vector<int> (n,0));
        int count=1;
        int top=0,left=0,bottom=n-1,right=n-1;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;++i)
            {
                v[top][i]=count;
                count++;
            }
            top++;
            for(int i=top;i<=bottom;++i)
            {
                v[i][right]=count;
                count++;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;--i)
                {
                    v[bottom][i]=count;
                    count++;
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;--i)
                {
                    v[i][left]=count;
                    count++;
                }
                left++;
            }
        }
        return v;
    }
};