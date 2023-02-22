class Solution {
public:
    int reinitializePermutation(int n) 
    {
        int count=0;
        vector<int> arr(n,0);
        for(int i=0;i<n;++i)
        {
            arr[i]=i;
        }
        
        vector<int> copy = arr;
        while(true)
        {
            count++;
                vector<int> copy2=copy;
                for(int i=0;i<n;++i)
                {
                    if(i%2==0)
                    {
                        copy[i]=copy2[i/2];
                    }
                    else
                    {
                        copy[i]=copy2[(n/2)+((i-1)/2)];
                    }
                }
            if(copy==arr)
                break;
        }
        return count;
    }
};