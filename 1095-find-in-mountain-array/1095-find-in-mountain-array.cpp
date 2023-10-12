/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
         //find the peak index
        int left=1,right=mountainArr.length()-2;
        int index=1;
         while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        index=left;
        
        int low=0,high=index;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(target < mountainArr.get(mid))
            {
                high=mid-1;
            }
            else
                low=mid+1;  
        }
        
        
        low=index,high=mountainArr.length()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(target > mountainArr.get(mid))
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return -1;
    }
};