class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        int index;
        while((index = s.find(part,0)) != string::npos)
        {
            string st1 = s.substr(0,index);
            string st2 = s.substr(index+part.size());
            s=st1+st2;
        }
        return s;
    }
};