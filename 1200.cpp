class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int mindiff = arr[1] - arr[0]; // little logic of kadane's algorithm to get the minimum difference of any two values in the array
        for (int i = 1; i < arr.size(); ++i)
        {
            int res = arr[i] - arr[i - 1];
            mindiff = min(res, mindiff);
        }
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i = 1; i < arr.size(); ++i)
        {
            if ((arr[i] - arr[i - 1]) == mindiff)
            {
                temp.push_back(arr[i - 1]);
                temp.push_back(arr[i]);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};