class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> frequency(26,0);
        for(int i=0;i<s.size();++i)
        {
            frequency[s[i]-'a']++;
        }
        
        vector<bool> visited(26,false);
        
        stack<char> nodes;
        for(int i=0;i<s.size();++i)
        {
            if(visited[s[i]-'a'])
            {
                frequency[s[i]-'a']--;
                continue;
            }
            while(!nodes.empty() && nodes.top()>s[i] && frequency[nodes.top()-'a']>0)
            {
                visited[nodes.top()-'a']=false;
                nodes.pop();
            }
            
            nodes.push(s[i]);
            frequency[s[i]-'a']--;
            visited[s[i]-'a']=true;
        }
        
        string ans="";
        while(!nodes.empty())
        {
            ans+=nodes.top();
            nodes.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};