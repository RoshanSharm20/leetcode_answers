// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n) // basic question of first occurence of bad version
    {
        long long int low = 1;
        long long int high = n;
        while (low <= high)
        {
            long long int mid = ((low + high) / 2);
            if (isBadVersion(mid))
            {
                if (isBadVersion(mid) != isBadVersion(mid - 1))
                    return mid;
                else
                    high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return -1;
    }
};