class Solution
{
public:
    bool isfeasible(vector<int> arr, int n, int k, int ans) // question of type allocate minimum pages in binary search
    {
        int req = 1, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((sum + arr[i]) > ans)
            {
                req++;
                sum = arr[i];
            }
            else
                sum += arr[i];
        }
        if (req <= k)
            return true;
        else
            return false;
    }
    int shipWithinDays(vector<int> &arr, int days)
    {
        int sum = 0, mx = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            sum += arr[i];
            mx = max(mx, arr[i]);
        }
        int low = mx, high = sum;
        int res = 0;
        while (low <= high)
        {
            int mid = ((low + high) / 2);
            if (isfeasible(arr, arr.size(), days, mid))
            {
                high = mid - 1;
                res = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};