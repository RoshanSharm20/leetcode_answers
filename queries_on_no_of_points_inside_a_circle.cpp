class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto circle : queries)
        {
            int count = 0;
            for (auto point : points)
            {
                if ((pow(circle[2], 2)) >= ((pow(point[0] - circle[0], 2)) + (pow(point[1] - circle[1], 2)))) // condition for a point to be inside a circle
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};