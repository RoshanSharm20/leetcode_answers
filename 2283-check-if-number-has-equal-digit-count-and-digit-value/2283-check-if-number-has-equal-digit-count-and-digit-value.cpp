class Solution {
public:
    bool digitCount(string num) 
    {
        map<int,int> nodes;
        for(int i=0;i<num.size();++i)
            nodes[num[i]-48]+=1;
        for(int i=0;i<num.size();++i)
        {
            if((num[i]-48)!=nodes[i])
                return false;
        }
        return true;
    }
};