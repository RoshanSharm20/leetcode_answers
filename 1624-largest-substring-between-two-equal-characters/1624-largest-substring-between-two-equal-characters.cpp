class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        vector<int> nodes(26,-1);
        nodes[s[0]-'a']=0;
        int max_length=-1;
        for(int i=1;i<s.size();++i)
        {
            if(nodes[s[i]-'a']!=-1)
            {
                max_length = max(max_length,i-nodes[s[i]-'a']-1);
            }
            else
                nodes[s[i]-'a']=i;
        }
        
        
        return max_length;
    }
};