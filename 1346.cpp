class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            int m = arr[i];
            int low = 0;
            int high = arr.size() - 1;
            while (low <= high)
            {
                int mid = ((low + high) / 2);
                if (arr[mid] == (2 * m))
                {
                    if (mid != i) // corner case when 0 is included in array as it can consider itself it's multiple giving wrong result
                        return true;
                }
                if (arr[mid] > (2 * m))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};