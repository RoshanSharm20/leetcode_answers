class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) 
    {
        set<pair<int,int>> pairs;//to store the pairs as per their order
        vector<int> adj[n];//creating a bi-directional adjacency list to perform bfs  
        for(int i=0;i<c.size();++i)
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
            pairs.insert({c[i][0],c[i][1]});
        }
        //bfs algo
        queue<int> nodes;
        vector<bool> visited(n,false);
        visited[0]=true;
        nodes.push(0);
        int count=0;//to count the number of edges that have to be flipped
        while(!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();
            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    if(pairs.find({it,node})==pairs.end())//if pair from child to parent doesn't exist,it means it has to flipped
                        count++;
                    nodes.push(it);
                    visited[it]=true;
                }
            }
        }
        return count;
    }
};