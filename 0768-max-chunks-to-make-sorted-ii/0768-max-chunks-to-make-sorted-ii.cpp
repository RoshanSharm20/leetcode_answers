class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> left_max(n+1),right_min(n+1);
        int left=INT_MIN,right=INT_MAX;
        for(int i=0;i<n;++i)
        {
            left=max(left,arr[i]);
            left_max[i]=left;
        }
        left_max[n]=left;
        right_min[n]=right;
        for(int i=n-1;i>=0;--i)
        {
            right = min(right,arr[i]);
            right_min[i]=right;
        }
        
        int chunks=0;
        for(int i=0;i<n;++i)
        {
            if(left_max[i]<=right_min[i+1])
                chunks++;
        }
        
        return chunks;
    }
};