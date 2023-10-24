class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows>=s.size() || numRows==1)
            return s;
        int x = (numRows*2)-2,y=0;
        
        string st="";
        for(int i=0;i<numRows;++i)
        {
            if(i==0)
            {
                int k=i;
                while(k<s.size())
                {
                    st+=s[k];
                    k+=x;
                }
                x-=2;
                y+=2;
            }
            else if(i==numRows-1)
            {
                int k=i;
                while(k<s.size())
                {
                    st+=s[k];
                    k+=y;
                }
                x-=2;
                y+=2;
            }
            else
            {
                int k=i;
                while(k<s.size())
                {
                    st+=s[k];
                    k+=x;
                    if(k<s.size())
                        st+=s[k];
                    k+=y;
                }
                x-=2;
                y+=2;
            }
        }
        return st;
    }
};