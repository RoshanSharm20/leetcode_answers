class Solution {
public:
    void bfs(int i, vector<vector<int>>&rooms, vector<int>&vis)
    {
        vis[i]=1;
        for(auto &keys:rooms[i])
        {
            if(!vis[keys])
            bfs(keys,rooms,vis);
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