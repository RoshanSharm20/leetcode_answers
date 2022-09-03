class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        vector<pair<int, int>> v; // i like the given data in pairs so made vector of pairs where first value is no of units per box and second value represents no of boxes
        int sum = 0;
        for (auto it : boxTypes)
        {
            v.push_back({it[1], it[0]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>()); // sorted in descending order
        for (auto it : v)
        {
            if ((truckSize - it.second) >= 0)
            {
                sum += (it.first * it.second);
                truckSize -= it.second;
            }
            else if ((truckSize > 0) && (truckSize - it.second) < 0) // to counter the case where truck has capacity left but the pair capacity is more so only the truckcapacity no of boxes are loaded
            {
                sum += (truckSize * it.first);
                truckSize -= it.second;
                break;
            }
        }
        return sum;
    }
};