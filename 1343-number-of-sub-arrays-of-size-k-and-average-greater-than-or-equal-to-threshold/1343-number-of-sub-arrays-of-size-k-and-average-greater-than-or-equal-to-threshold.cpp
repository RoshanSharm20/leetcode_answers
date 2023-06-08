class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int start=0,end=0,sum=0,count=0;
        while(end<arr.size())
        {
            sum+=arr[end];
            if((end-start+1)<k)
                end++;
            else
            {
                if((sum/k)>=threshold)
                    count++;
                sum-=arr[start];
                start++;
                end++;
            }
        }
        return count;
    }
};