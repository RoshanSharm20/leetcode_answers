class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum=0;
        int i=0;
        int j=mat.size()-1;
        for( auto &it : mat)
        {
            if(i!=j)
                sum+=it[i]+it[j];
            if(i==j)
                sum+=it[i];
            i++;
            j--;
        }
        return sum;
    }
};