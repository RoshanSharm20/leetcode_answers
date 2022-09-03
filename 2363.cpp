class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> m;
        for (auto vec : items1)
            m[vec[0]] = vec[1];
        for (auto vec : items2)
        {
            if (m.find(vec[0]) == m.end())
            {
                m[vec[0]] = vec[1];
            }
            else
            {
                m[vec[0]] = m[vec[0]] + vec[1];
            }
        }
        vector<vector<int>> ans;
        vector<int> temp;
        for (auto it : m)
        {
            temp.push_back(it.first); // iterators are pairs
            temp.push_back(it.second);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};