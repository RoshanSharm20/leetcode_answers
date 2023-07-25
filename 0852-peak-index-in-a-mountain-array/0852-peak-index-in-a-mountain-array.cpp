class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {   
        int low=0;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid-1])
            {
                if(arr[mid]>arr[mid+1])
                    return mid;
                else
                    low=mid;
            }
            else
                high=mid;
            
        }
        return 0;
    }
};