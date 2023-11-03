class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        int last=0;
        for(int i=0;i<target.size();++i)
        {
            int front = target[i]-last;
            for(int x=1;x<front;++x)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            last=target[i];
        }
        
        return ans;
    }
};