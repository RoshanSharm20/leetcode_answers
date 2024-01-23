class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        int ans=0;
        int n = arr.size();
        for(int i=0;i<pow(2,n);++i)
        {
            // cout<<i<<endl;
            vector<bool> visited(26,false);
            bool possible = true;
            // string curr_ans="";
            int curr_ans=0;
            for(int j=0;j<n;++j)
            {
                if((i&(1<<j))!=0)
                {
                    for(int k=0;k<arr[j].size();++k)
                    {
                        if(visited[arr[j][k]-'a']==true)
                        {
                            possible = false;
                            break;
                        }

                        visited[arr[j][k]-'a']=true;
                    }
                    curr_ans+=arr[j].size();
                }
            }
            
            if(possible)
            {
                if(curr_ans>ans)
                    ans=curr_ans;
            }
            
        }
        return ans;
    }
};