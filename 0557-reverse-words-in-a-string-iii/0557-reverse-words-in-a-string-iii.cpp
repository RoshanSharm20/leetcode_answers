class Solution {
public:
    string reverseWords(string s) 
    {
        int i;
        int start=0;
        string str="";
        string collect="";
         for(i=0;i<s.size();++i)
         {
             if(s[i]==' ')
             {
                 reverse(collect.begin(),collect.end());
                 str+=collect+' ';
                 collect="";
             }
             else
             {
                 collect+=s[i];
             }
         }
        reverse(collect.begin(),collect.end());
        str+=collect;
        return str;
    }
};