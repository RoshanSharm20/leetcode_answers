class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int x=intervals[0][0];
        int y=intervals[0][1];
        for(int i=1;i<intervals.size();++i)
        {
            if((y>=intervals[i][0]) && (x<=intervals[i][1]))
            {
                x=min(x,intervals[i][0]);
                y=max(y,intervals[i][1]);
            }
            else
            {
                vector<int> v;
                v.push_back(x);
                v.push_back(y);
                ans.push_back(v);
                x=intervals[i][0];
                y=intervals[i][1];
            }
        }
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        ans.push_back(v);
        return ans;
    }
};