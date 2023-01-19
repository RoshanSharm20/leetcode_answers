class Solution {
public:
    void countSort(vector<vector<int>>&mat,int row,int col)
    {
        vector<int> count(101,0);
        int m=mat.size();
        int n=mat[0].size();
        int i=row;
        int j=col;
        while(i<m && j<n)
        {
            count[mat[i][j]]++;
            i++;
            j++;
        }
        i=row;
        j=col;
        for(int k=1;k<=100;++k)
        {
            while(count[k]>0)
            {
                count[k]--;
                mat[i][j]=k;
                i++;
                j++;
            }
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;++i)
        {
            countSort(mat,i,0);
        }
        
        for(int j=0;j<n;++j)
        {
            countSort(mat,0,j);
        }
        return mat;
    }
};