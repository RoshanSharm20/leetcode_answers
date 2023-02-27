class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int,double>> nodes;
        for(int i=0;i<speed.size();++i)
        {
            double time = double (target-position[i])/speed[i];
            nodes.push_back({position[i],time});
        }
        sort(nodes.begin(),nodes.end());
        int count=0;
        double tt=nodes[nodes.size()-1].second;
        for(int i=nodes.size()-2;i>=0;--i)
        {
            if(nodes[i].second>tt)
            {
                count++;
                tt=nodes[i].second;
            }
        }
        return count+1;
    }
};