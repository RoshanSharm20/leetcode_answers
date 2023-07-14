class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        int n=arr.size(),max_val=1;
        vector<int> count(n,1);
        map<int,int> nodes;
        // for(int i=0;i<n;++i)
        // {
        //     nodes[arr[i]]=i;
        // }
        nodes[arr[0]]=0;
        for(int i=1;i<n;++i)
        {
            int x=arr[i]-difference;
            if(nodes.find(x)!=nodes.end() && nodes[x]<i)
            {
                count[i]=1+count[nodes[x]];
                max_val=max(max_val,count[i]);
            }
            nodes[arr[i]]=i;
        }
        return max_val;
        // return temp.size();
    }
};