class Solution {
public:
    int totalFruit(vector<int>& f) 
    {
        map<int,int> nodes;
        int start=0,end=0,count=0,res=0;
        while(end<f.size())
        {
            nodes[f[end]]+=1;
            if(nodes[f[end]]==1)
                count++;
            // if(count<2)
            //     end++;
            if(count<=2)
            {
                res=max(res,end-start+1);
                end++;
            }
            else if(count>2)
            {
                while(count>2)
                {
                    nodes[f[start]]-=1;
                    if(nodes[f[start]]==0)
                        count--;
                    start++;
                }
                end++;
            }
        }
        return res;
    }
};