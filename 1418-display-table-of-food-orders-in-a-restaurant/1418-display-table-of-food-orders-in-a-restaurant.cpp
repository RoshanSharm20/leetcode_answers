class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) 
    {
        map<string,vector<int>> dish_counts;
        set<int> tables;
        for(auto it:orders)
        {
            dish_counts[it[2]].push_back(stoi(it[1]));
            tables.insert(stoi(it[1]));
        }
        
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back("Table");
        for(auto it:dish_counts)
        {
            temp.push_back(it.first);
        }
        ans.push_back(temp);
        for(auto it:tables)
        {
            vector<string> t;
            string num = to_string(it);
            t.push_back(num);
            for(auto m:dish_counts)
            {
                int n = count(m.second.begin(),m.second.end(),it);
                string n_o = to_string(n);
                t.push_back(n_o);
            }
            ans.push_back(t);
        }
        return ans;
    }
};