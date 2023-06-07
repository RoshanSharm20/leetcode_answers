class Solution {
public:
    string minWindow(string s, string t) 
    {
        string ans="";
        int res=INT_MAX,x=-1,y=-1;
        int start=0,end=0,count=0;
        map<char,int> nodes;
        for(auto it:t)
            nodes[it]+=1;
        count=nodes.size();
        while(end<s.size())
        {
            if(nodes.find(s[end])!=nodes.end())
            {
                nodes[s[end]]-=1;
                if(nodes[s[end]]==0)
                    count--;
            }
            if(count>0)
                end++;
            else if(count==0)
            {
                if(res>(end-start+1))
                {
                    res=end-start+1;
                    ans=s.substr(start,end-start+1);
                }
                while(count==0)
                {
                    if(nodes.find(s[start])!=nodes.end())
                    {
                        nodes[s[start]]+=1;
                        if(nodes[s[start]]==1)
                        {
                            count++;
                            if((end-start+1)<res)
                            {
                                res=end-start+1;
                                ans=s.substr(start,end-start+1);
                            }
                        }
                    }
                    start++;
                }
                end++;
            }
        }
        // ans=s.substr(x,y);
        return ans;
    }
};