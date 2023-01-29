class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
    {
        vector<vector<int>> nodes;
        for(int i=0;i<triplets.size();++i)
        {
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2])
                nodes.push_back(triplets[i]);
        }
        
        if(nodes.size()==0)
            return false;
        int a=nodes[0][0];
        int b=nodes[0][1];
        int c=nodes[0][2];
        
        for(int i=1;i<nodes.size();++i)
        {
            a=max(a,nodes[i][0]);
            b=max(b,nodes[i][1]);
            c=max(c,nodes[i][2]);
        }
        
        if(a==target[0] && b==target[1] && c==target[2])
            return true;
        return false;
    }
};