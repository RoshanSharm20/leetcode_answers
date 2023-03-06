class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        vector<int> v(2001);
        v[0]=0;
        for(int i=0;i<arr.size();++i)
        {
            v[arr[i]]=1;
        }
        int i;
        for(i=1;i<=2000;++i)
        {
            if(v[i]==0)
                k--;
            if(k==0)
                break;
        }
        return i;
    }
};