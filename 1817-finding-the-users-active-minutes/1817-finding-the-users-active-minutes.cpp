class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        vector<int> ans(k+1,0);
        map<int,set<int>> nodes;
        for(auto it:logs)
            nodes[it[0]].insert(it[1]);
        for(auto it:nodes)
        {
            int uam=it.second.size();
            ans[uam]++;
        }
        ans.erase(ans.begin());
        return ans;
    }
};