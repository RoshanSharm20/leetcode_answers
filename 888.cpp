class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int s1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int s2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        vector<int> ans;
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        for (int i = 0; i < aliceSizes.size(); ++i)
        {
            int low = 0;
            int high = bobSizes.size() - 1;
            int res = -1;
            int mid;
            while (low <= high)
            {
                mid = ((low + high) / 2);
                if ((s1 + bobSizes[mid] - aliceSizes[i]) == (s2 + aliceSizes[i] - bobSizes[mid]))
                {
                    res = mid;
                    break;
                }
                if ((s1 + bobSizes[mid] - aliceSizes[i]) < (s2 + aliceSizes[i] - bobSizes[mid]))
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            if (res != -1)
            {
                ans.push_back(aliceSizes[i]);
                ans.push_back(bobSizes[mid]);
                break;
            }
        }
        return ans;
    }
};