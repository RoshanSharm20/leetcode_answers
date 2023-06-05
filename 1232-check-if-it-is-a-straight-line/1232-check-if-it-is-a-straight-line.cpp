class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) 
    {
        sort(c.begin(),c.end());
        if(c.size()==2)
            return true;
        double slope;
        if((c[1][0]-c[0][0])!=0)
        {
            slope = (c[1][1]-c[0][1])/(c[1][0]-c[0][0]);
        }
        else
            slope = INT_MAX;
        for(int i=2;i<c.size();++i)
        {
            double check;
            if((c[i][0]-c[i-1][0])!=0)
            {
                check = (c[i][1]-c[i-1][1])/(c[i][0]-c[i-1][0]);
            }
            else
            {
                check = INT_MAX;
            }
            if(slope!=check)
                return false;
        }
        return true;
    }
};