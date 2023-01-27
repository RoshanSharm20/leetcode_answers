class Solution {
public:
    set<string> ans;
    void solution(string& tiles,vector<bool>& visited,string& asf)
    {
        for(int i=0;i<visited.size();++i)
        {
            if(!visited[i])
            {
                asf.push_back(tiles[i]);
                visited[i]=true;
                ans.insert(asf);
                solution(tiles,visited,asf);
                asf.pop_back();
                visited[i]=false;
            }
        }
    }
    int numTilePossibilities(string tiles) 
    {
        string asf="";
        vector<bool> visited(tiles.size(),false);
        solution(tiles,visited,asf);
        return ans.size();
    }
};