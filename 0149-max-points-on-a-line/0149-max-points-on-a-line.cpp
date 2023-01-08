class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        map<int,map<double,int>> frequency;
        for(int i=0;i<points.size();++i)
        {
            for(int j=0;j<points.size();++j)
            {
                if(i!=j)
                {
                    if(points[i][0]==points[j][0])
                    {
                        frequency[i][INT_MAX]+=1;
                    }
                    else
                    {
                        double y=points[j][1]-points[i][1];
                        double x=points[j][0]-points[i][0];
                        frequency[i][y/x]+=1;
                    }
                }
            }
        }
        int max_count=0;
        for(auto it : frequency)
        {
            for(auto it1 : it.second)
            {
                max_count=max(max_count,it1.second);
            }
        }
        return max_count+1;
    }
};