class Solution {
public:
    vector<string> ans;
    void solution(string& s,int index)
    {
        if(index==s.size())
        {
            ans.push_back(s);
            return;
        }
        if((s[index]>='a' && s[index]<='z'))
        {
            s[index]=char(s[index]-32);
            solution(s,index+1);
            s[index]=char(s[index]+32);
            solution(s,index+1);
        }
        else if((s[index]>='A' && s[index]<='Z'))
        {
            s[index]=char(s[index]+32);
            solution(s,index+1);
            s[index]=char(s[index]-32);
            solution(s,index+1);
        }
        else
        {
            solution(s,index+1);
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        solution(s,0);
        return ans;
    }
};