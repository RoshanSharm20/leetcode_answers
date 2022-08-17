class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> p; // declare a pait to maintain a value and set bit relationship
        vector<int> ans;          // answer vector
        for (int i = 0; i < arr.size(); i++)
        {
            int n = arr[i];
            int count = 0;
            while (n > 0)
            {
                n = n & (n - 1);
                count++;
            }
            p.push_back({count, arr[i]}); // insert the pair of (number of set bits and the integer value)
        }
        sort(p.begin(), p.end()); // sort first based on number of set bits and then based on the integer value
        for (auto it : p)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};