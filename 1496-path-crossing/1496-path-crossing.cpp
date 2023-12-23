class Solution {
public:
    bool isPathCrossing(string path) 
    {
        set<pair<int,int>> nodes;
        nodes.insert({0,0});
        int x=0,y=0;
        for(int i=0;i<path.size();++i)
        {
            if(path[i]=='N')
                y+=1;
            else if(path[i]=='S')
                y-=1;
            else if(path[i]=='E')
                x+=1;
            else if(path[i]=='W')
                x-=1;
            
            if(nodes.find({x,y})!=nodes.end())
                return true;
            nodes.insert({x,y});
        }
        return false;
    }
};