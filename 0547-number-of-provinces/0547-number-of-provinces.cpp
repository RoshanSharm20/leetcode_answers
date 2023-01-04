class Solution {
public:
    void dfs(int index,vector<int> nodes[],vector<bool>& visited)
    {
        for(int i=0;i<nodes[index].size();++i)
        {
            if(!visited[nodes[index][i]])
            {
                visited[nodes[index][i]]=true;
                dfs(nodes[index][i],nodes,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        vector<int> nodes[isConnected.size()+1];
        vector<bool> visited(isConnected.size()+1,false);
        for(int i=0;i<isConnected.size();++i)
        {
            for(int j=0;j<isConnected[0].size();++j)
            {
                if(isConnected[i][j]==1)
                {
                    nodes[i+1].push_back(j+1);
                    nodes[j+1].push_back(i+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<visited.size();++i)
        {
           if(!visited[i])
           {
               visited[i]=true;
               count++;
               dfs(i,nodes,visited);
           }
        }
        return count;
    }
};
// class Solution {
// public:
//     void dfs(int i,vector<int> nodes[],vector<bool>& visited)
//     {
//         for(int j=0;j<nodes[i].size();++i)
//         {
//             if(!visited[nodes[i][j]])
//             {
//                 visted[nodes[i][j]]=true;
//                 dfs(nodes[i][j],nodes,visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) 
//     {
//         int count=0;
//         vector<bool> visited(isConnected[0].size(),false);
//         vector<int> nodes(isConnected.size()+1);
//         for(int i=0;i<isConnected.size();++i)
//         {
//             for(int j=0;j<isConnected[0].size();++j)
//             {
//                 if(isConnected[i][j]==1)
//                 {
//                     nodes[i+1].push_back(j+1);
//                     nodes[j+1].push_back(i+1);
//                 }
//             }
//         }
//         for(int i=1;i<visited.size();++i)
//         {
//             if(!visited[i])
//             {
//                 count++;
//                 visited[i]=true;
//                 dfs(i,nodes,visited);
//             }
//         }
//         return count;
//     }
// };