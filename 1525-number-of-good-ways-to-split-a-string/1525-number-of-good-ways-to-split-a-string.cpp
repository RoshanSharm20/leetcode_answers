class Solution {
public:
    int numSplits(string s) 
    {
        int n = s.size();
        vector<int> left(n,0),right(n,0);
        long long int left_side=0;
        int count = 0;
        for(int i=0;i<s.size();++i)
        {
            int index = s[i]-'a';
            if(left_side&(1<<index))
                left[i]=count;
            else
            {
                count++;
                left_side|=(1<<index);
                left[i]=count;
            }
        }
        
        count=0;
        long long int right_side=0;
        for(int i=s.size()-1;i>=0;--i)
        {
            int index = s[i]-'a';
            if(right_side&(1<<index))
                right[i]=count;
            else
            {
                count++;
                right_side|=(1<<index);
                right[i]=count;
            }
        }
        
        int total=0;
        for(int i=0;i<s.size()-1;++i)
        {
            if(left[i]==right[i+1])
                total++;
        }
        return total;
    }
};