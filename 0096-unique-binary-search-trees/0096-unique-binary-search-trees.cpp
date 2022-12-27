class Solution {
public:
    map<int,int> reserves;
    int numTrees(int n) 
    {
        if(n==0 || n==1)
            return 1;
        int total_count=0;
        for(int i=1;i<=n;++i)
        {
            int left,right;
            if(reserves.find(i-1)!=reserves.end())
                left=reserves[i-1];
            else
            {
                left = numTrees(i-1);
                reserves[i-1]=left;
            }
            if(reserves.find(n-i)!=reserves.end())
                right=reserves[n-i];
            else
            {
                right = numTrees(n-i);
                reserves[n-i]=right;
            }
                
            total_count+=(left*right);
        }
        return total_count;
    }
};