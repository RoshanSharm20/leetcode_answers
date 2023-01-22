class Solution {
public:
    vector<vector<string>> ans;
    void solution(string& s,int index,vector<string>& asf)
    {
        if(index==s.size())
        {
            for(auto it:asf)
            {
                for(int i=0;i<it.size()/2;++i)
                {
                    if(it[i]!=it[it.size()-i-1])
                        return;
                }
            }
            ans.push_back(asf);
            return;
        }
        
        string temp;
        temp.push_back(s[index]);
        asf.push_back(temp);
        solution(s,index+1,asf);
        asf.pop_back();
        if(asf.size()>0)
        {
            string original = asf[asf.size()-1];
            temp = original;
            temp+=s[index];
            asf.pop_back();
            asf.push_back(temp);
            solution(s,index+1,asf);
            asf.pop_back();
            asf.push_back(original);
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string> asf;
        solution(s,0,asf);
        return ans;
    }
};