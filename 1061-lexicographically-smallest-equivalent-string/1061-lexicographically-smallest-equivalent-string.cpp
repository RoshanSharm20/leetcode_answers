class Solution {
public:
    void dfs(int &minchar,int src,vector<int> adj[],vector<bool> &visited,vector<int> &visitComponents)
    {
        visited[src]=true;
        visitComponents.push_back(src);
        minchar = min(minchar,src);
        for(auto it:adj[src])
        {
            if(!visited[it])
            {
                dfs(minchar,it,adj,visited,visitComponents);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        vector<int> adj[26];
        for(int i=0;i<s1.size();++i)
        {
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        
        vector<int> charMap(26,0);
        for(int i=0;i<26;++i)
            charMap[i]=i;
        
        vector<bool> visited(26,false);
        for(int i=0;i<26;++i)
        {
            if(!visited[i])
            {
                int minchar = i;
                vector<int> visitComponents;
                dfs(minchar,i,adj,visited,visitComponents);
                
                for(auto it:visitComponents)
                    charMap[it]=minchar;
                
            }
        }
        string ans;
        for(auto it:baseStr)
        {
            ans+=(char)(charMap[it-'a']+'a');
        }
        return ans;
    }
};