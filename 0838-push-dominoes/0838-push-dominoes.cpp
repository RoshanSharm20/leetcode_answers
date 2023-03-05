class Solution {
public:
    void makeChanges(int i,int j,string& s)
    {
        if(s[i]=='L' && s[j]=='L')
        {
            while(i!=j)
            {
                s[i]='L';
                i++;
            }
        }
        else if(s[i]=='R' && s[j]=='R')
        {
            while(i!=j)
            {
                s[i]='R';
                i++;
            }
        }
        else if(s[i]=='L' && s[j]=='R')
        {
            
        }
        else
        {
            if((j-i-1)%2==0)
            {
                int mid = (j+i)/2;
                while(i<=mid)
                {
                    s[i]='R';
                    i++;
                }
                while(i<j)
                {
                    s[i]='L';
                    i++;
                }
            }
            else
            {
                int mid = (j+i)/2;
                while(i<mid)
                {
                    s[i]='R';
                    i++;
                }
                i = mid+1;
                while(i<j)
                {
                    s[i]='L';
                    i++;
                }
            }
        }
    }
    string pushDominoes(string dominoes) 
    {
        string s = 'L'+dominoes+'R';
        int i=0,j=1;
        while(j<s.size())
        {
            while(s[j]=='.')
                j++;
            makeChanges(i,j,s);
            i=j;
            j++;
        }
        string st(s.begin()+1,s.begin()+s.size()-1);
        return st;
    }
};