class Solution {
public:
    vector<int> solution(map<int,vector<int>> &nodes,int starter)
    {
        unordered_set<int> st;
        vector<int> ans;
        ans.push_back(starter);
        st.insert(starter);
        bool available = true;
        while(available)
        {
            available=false;
            for(auto it:nodes[starter])
            {
                if(st.find(it)==st.end())
                {
                    ans.push_back(it);
                    st.insert(it);
                    starter = it;
                    available = true;
                }
            }
        }
        return ans;
    }
    vector<int> restoreArray(vector<vector<int>>& aP) 
    {
        map<int,vector<int>> nodes;
        for(int i=0;i<aP.size();++i)
        {
            nodes[aP[i][0]].push_back(aP[i][1]);
            nodes[aP[i][1]].push_back(aP[i][0]);
        }
        
        int starter1 = -1e9,starter2 = -1e9;
        for(auto it:nodes)
        {
            if(it.second.size()==1)
            {
                if(starter1==-1e9)
                {
                    starter1 = it.first;
                    continue;
                }
                else
                {
                    starter2 = it.first;
                    break;
                }
            }
        }
        
        auto it = solution(nodes,starter1);
        auto it2 = solution(nodes,starter2);
        if(it.size()==aP.size()+1)
            return it;
        return it2;
    }
};