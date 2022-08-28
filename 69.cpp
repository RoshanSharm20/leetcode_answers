class Solution
{
public:
    int mySqrt(int x)
    {
        long long int low = 0;
        long long int high = x;
        long long int res = 0;
        while (low <= high)
        {
            long long int mid = ((low + high) / 2);
            if ((mid * mid) <= x)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }
};