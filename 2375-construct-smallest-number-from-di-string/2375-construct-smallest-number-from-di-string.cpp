class Solution {
public:
    string ans;
    bool solution(string& pattern,vector<bool>& visited,string& asf)
    {
        if(asf.size()==pattern.size()+1)
        {
           for(int i=0;i<pattern.size();++i)
           {
               if(pattern[i]=='I' && asf[i]>asf[i+1])
                   return false;
               if(pattern[i]=='D' && asf[i]<asf[i+1])
                   return false;
           }
            ans=asf;
            return true;
        }
        
        for(int i=1;i<visited.size();++i)
        {
            if(!visited[i])
            {
                visited[i]=true;
                string num = to_string(i);
                string original=asf;
                asf+=num;
                if(solution(pattern,visited,asf))
                    return true;
                asf=original;
                visited[i]=false;   
            }
        }
        return false;
    }
    string smallestNumber(string pattern) 
    {
        vector<bool> visited(10,false);
        string asf="";
        solution(pattern,visited,asf);
        return ans;
    }
};