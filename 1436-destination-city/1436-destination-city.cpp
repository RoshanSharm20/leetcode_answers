class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        map<string,string> m;
        set<string> s;
        for(auto it : paths)
        {
            m[it[0]]=it[1];
            s.insert(it[0]);
            s.insert(it[1]);
        }
        for(auto it : s)
        {
            if(m.find(it)==m.end())
                return it;
        }
        return 0;
    }
};