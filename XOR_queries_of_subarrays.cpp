class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<int> prefix; // make a prefix vector to store all the xor values beforehand
        prefix.insert(prefix.begin(), 0);
        for (int i = 1; i <= arr.size(); i++)
        {
            int val = prefix[i - 1] ^ arr[i - 1];
            prefix.push_back(val);
        }
        for (auto pr : queries)
        {
            int value = prefix[pr[1] + 1] ^ prefix[pr[0]]; // computation to be careful
            ans.push_back(value);
        }
        return ans;
    }
};