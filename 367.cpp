class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return 1;
        long long int low = 1;
        long long int high = (num / 2);
        while (low <= high) // binary search algo
        {
            long long int mid = ((low + high) / 2);
            long long int msq = mid * mid;
            if (msq == num)
                return true;
            if (msq > num)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};