class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end(), greater<int>()); // sort in decreasing order
        int max = 0;
        for (int i = 1; i < 2 * ((piles.size()) / 3); i = i + 2) // the opitimal pairs can always be first 2 elements and 1 last element manner
        {
            max += piles[i]; // every second value sum will yield the maximum value
        }
        return max;
    }
};