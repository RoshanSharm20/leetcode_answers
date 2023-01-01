class Solution {
public:
    vector<string> solution(string& s)
    {
        vector<string> answer;
        string ans="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
                answer.push_back(ans);
                ans="";
            }
            else
                ans+=s[i];
        }
        answer.push_back(ans);
        return answer;
    }
    bool wordPattern(string pattern, string s) 
    {
        vector<string> str = solution(s);
        map<string,int> m;
        map<char,int> mc;
        if(str.size()!=pattern.size())
            return false;
        char ch = 'a';
        for(int i=0;i<pattern.size();++i)
        {
            if(mc.find(pattern[i])==mc.end())
            {
                mc[pattern[i]]=ch;
                ch++;
            }
        }
        ch='a';
        for(int i=0;i<str.size();++i)
        {
            if(m.find(str[i])==m.end())
            {
                m[str[i]]=ch;
                ch++;
            }
        }
        string pat,wor;
        for(int i=0;i<pattern.size();++i)
        {
            pat+=mc[pattern[i]];
            wor+=m[str[i]];
        }
        return pat==wor;   
    }
};