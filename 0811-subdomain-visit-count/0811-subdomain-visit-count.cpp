class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        unordered_map<string,int> nodes;
        for(int i=0;i<cpdomains.size();++i)
        {
            int num=0;
            for(int j=0;j<cpdomains[i].size();++j)
            {
                if(cpdomains[i][j]==' ')
                {
                    num=stoi(cpdomains[i].substr(0,j));
                    break;
                }
            }
            for(int j=cpdomains[i].size()-1;j>=0;--j)
            {
                if(cpdomains[i][j]=='.')
                {
                    string str = cpdomains[i].substr(j+1);
                    nodes[str]+=num;
                }
                if(cpdomains[i][j]==' ')
                {
                   string str = cpdomains[i].substr(j+1);
                    nodes[str]+=num;
                    break;
                }
            }
        }
        vector<string> ans;
        for(auto it:nodes)
        {
            string str=to_string(it.second)+" "+it.first;
            ans.push_back(str);
        }
        return ans;
    }
};