class Solution {
public:
    void bfs(int i, vector<vector<int>>&rooms, vector<int>&vis)
    {
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto &keys:rooms[node])
            {
                if(!vis[keys]){
                vis[keys]= 1;
                q.push(keys);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        bfs(0,rooms,vis);
        for(auto &it:vis)
        if(it==0) return false;
        return true;
    }
};