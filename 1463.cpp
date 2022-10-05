class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, string> m; // map to keep track of which city connects to which other city
        set<string> s;         // set of all the cities that exist
        for (auto it : paths)
        {
            m[it[0]] = it[1];
            s.insert(it[0]);
            s.insert(it[1]);
        }
        for (auto it : s)
        {
            if (m.find(it) == m.end()) // if no outgoing path to any of the city exist then print that value
                return it;
        }
        return 0;
    }
};