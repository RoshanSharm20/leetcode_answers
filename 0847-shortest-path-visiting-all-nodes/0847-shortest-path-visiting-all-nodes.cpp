class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        if(n==1)
            return 0;
        
        int visited_all = (1<<n)-1;
        
        vector<vector<int>> node_mask(n,vector<int>(visited_all+1));
        
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i)
        {
            q.push({i,(1<<i)});
        }
        
        
        int pathlength=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
                auto it = q.front();
                q.pop();
                int curr_node = it.first;
                int bitmask = it.second;
                
                if(bitmask==visited_all)
                    return pathlength;
                for(auto g:graph[curr_node])
                {
                    int nextbitmask = bitmask|(1<<g);
                    
                    if(node_mask[g][nextbitmask])
                        continue;
                    
                    if(nextbitmask==visited_all)
                        return pathlength+1;
                    
                    node_mask[g][nextbitmask]=true;
                    q.push({g,nextbitmask});
                }
                size--;
            }
            pathlength++;
        }
        return -1;
    }
};