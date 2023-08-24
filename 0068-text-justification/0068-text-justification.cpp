class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ans;
        vector<pair<vector<string>,int>> nodes;
        vector<string> asf;
        int count = words[0].size();
        asf.push_back(words[0]);
        for(int i=1;i<words.size();++i)
        {
            if(count+1+words[i].size()<=maxWidth)
            {
                count+=(1+words[i].size());
                asf.push_back(words[i]);
            }
            else
            {
                nodes.push_back({asf,count});
                asf.clear();
                asf.push_back(words[i]);
                count=words[i].size();
            }
        }
        
        nodes.push_back({asf,count});
        
        for(int i=0;i<nodes.size();++i)
        {
            if(i==nodes.size()-1)
            {
                int rem_size = maxWidth - nodes[i].second;
                string st="";
                for(auto it:nodes[i].first)
                {
                    if(st.size()==0)
                        st+=it;
                    else
                    {
                        st+=' ';
                        st+=it;
                    }
                }
                for(int x=0;x<rem_size;++x)
                    st+=' ';
                ans.push_back(st);
                continue;
            }
            int rem_size = maxWidth - nodes[i].second;
            if(rem_size>0)
            {
                if(nodes[i].first.size()==1)
               {
                   auto it = nodes[i].first;
                   string st = it[0];
                   for(int x=0;x<rem_size;++x)
                   {
                       st+=' ';
                   }
                   ans.push_back(st);
               }
                else
                {
                    int size_to_add = rem_size/(nodes[i].first.size() - 1);
                    int extra = rem_size%(nodes[i].first.size() - 1);
                    string st="";
                    for(auto it:nodes[i].first)
                    {
                        if(st.size()==0)
                            st+=it;
                        else
                        {
                            for(int a=0;a<size_to_add;++a)
                                st+=' ';
                            st+=' ';
                            if(extra>0)
                            {
                                st+=' ';
                                extra--;
                            }
                            st+=it;
                        }
                    }
                    ans.push_back(st);
                }
            }
            else
            {
                string st="";
                for(auto it:nodes[i].first)
                {
                    if(st.size()==0)
                        st+=it;
                    else
                    {
                        st+=' ';
                        st+=it;
                    }
                }
                ans.push_back(st);
            }
        }
        return ans;
    }
};