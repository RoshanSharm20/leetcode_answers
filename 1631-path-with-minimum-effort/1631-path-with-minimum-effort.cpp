class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >nodes;
        nodes.push({0,{0,0}});
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        distance[0][0]=0;
        while(!nodes.empty())
        {
            auto it = nodes.top();
            nodes.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1)
                return diff;
            for(int i=0;i<4;++i)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort = max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                    if(newEffort < distance[nrow][ncol])
                    {
                        distance[nrow][ncol]=newEffort;
                        nodes.push({distance[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};