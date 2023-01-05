class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        vector<vector<int>> ans;
        int minx=points[0][0];
        int maxx=points[0][1];
        for(int i=1;i<points.size();++i)
        {
            if(points[i][0]>=minx && points[i][0]<=maxx)
            {
                minx=min(points[i][0],minx);
                maxx=min(points[i][1],maxx);
            }
            else
            {
                vector<int> temp={minx,maxx};
                ans.push_back(temp);
                minx=points[i][0];
                maxx=points[i][1];
            }
        }
        vector<int> temp={minx,maxx};
        ans.push_back(temp);
        return ans.size();
    }
};