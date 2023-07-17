class Solution {
public:
    static bool myComp(vector<int> &a,vector<int> &b)
    {
        if(a[1]<b[1])
            return true;
        else if(a[1]==b[1])
        {
            if(a[0]<b[0])
                return true;
            return false;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),myComp);
        int count=1,end=intervals[0][1];
        for(int i=1;i<intervals.size();++i)
        {
            if(end<=intervals[i][0])
            {
                count++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};