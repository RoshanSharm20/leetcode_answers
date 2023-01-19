class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) 
    {
        vector<int> ans;
        vector<int> permute(m,0);
        for(int i=0;i<m;++i)
        {
            permute[i]=i+1;
        }
        for(int i=0;i<queries.size();++i)
        {
            int num=queries[i];
            auto inde= find(permute.begin(),permute.end(),num);
            int index = inde-permute.begin();
            int val = permute[index];
            ans.push_back(index);
            permute.erase(inde);
            permute.insert(permute.begin(),val);
        }
        return ans;
    }
};