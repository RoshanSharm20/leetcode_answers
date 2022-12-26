class Solution {
public:
    vector<int> pathInZigZagTree(int label) 
    {
        int totalnodes = 0;
        int levelnodes = 1;
        while(totalnodes < label)
        {
            totalnodes+=levelnodes;
            levelnodes*=2;
        }
        levelnodes/=2;
        vector<int> ans;
        while(label!=1)
        {
            ans.push_back(label);
            int comp = 3*levelnodes - label -1;
            int parent = comp/2;
            label = parent;
            levelnodes/=2;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};