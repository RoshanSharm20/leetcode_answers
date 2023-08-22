class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        map<int,char> nodes;
        nodes[0]='Z';
        char ch = 'A';
        for(int i=1;i<=25;++i)
        {
            nodes[i]=ch;
            ch++;
        }
        
        string ans="";
        while(columnNumber>0)
        {
            if(columnNumber<=26)
            {
                if(columnNumber==26)
                    ans+="Z";
                else
                    ans+=nodes[columnNumber];
                break;
            }
            else
            {
                int rem = columnNumber%26;
                if(rem==0)
                {
                    ans += "Z";
                    columnNumber = (columnNumber-1)/26;
                }
                else
                {
                    ans+=nodes[rem];
                    columnNumber = columnNumber/26;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};