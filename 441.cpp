class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long int low = 1;
        long long int high = n;
        long long res = 0;
        // if(n==1)
        //     return 1;
        while (low <= high)
        {
            long long int mid = ((low + high) / 2);
            if (((mid * (mid + 1)) / 2) <= n) // sum of upto mid value rows is less than equal to no of coins
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