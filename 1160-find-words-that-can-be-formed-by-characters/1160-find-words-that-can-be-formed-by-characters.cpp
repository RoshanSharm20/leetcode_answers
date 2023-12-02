class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int count=0;
        vector<int> nodes(26,0);
        for(int i=0;i<chars.size();++i)
        {
            nodes[chars[i]-'a']+=1;
        }
        for(int i=0;i<words.size();++i)
        {
            vector<int> newnodes(26,0);
            for(int j=0;j<words[i].size();++j)
            {
                newnodes[words[i][j]-'a']+=1;
            }
            
            bool possible = true;
            for(int j=0;j<26;++j)
            {
                if(newnodes[j]>nodes[j])
                {
                    possible = false;
                    break;
                }
            }
            if(possible)
                count+=words[i].size();
        }
        
        return count;
    }
};