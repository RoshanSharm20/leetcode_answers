class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int count = 0;
        int capacity_c = capacity;
        for (int i = 0; i < plants.size(); ++i)
        {
            if (capacity >= plants[i])
            {
                capacity -= plants[i];
                count++;
            }
            else
            {
                count += (2 * i) + 1;
                capacity = capacity_c - plants[i];
            }
        }
        return count;
    }
};