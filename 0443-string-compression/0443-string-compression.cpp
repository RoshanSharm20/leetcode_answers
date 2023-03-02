class Solution {
public:
    int compress(vector<char>& chars) 
    {
        string ans="";
        char ch = chars[0];
        int count=1;
        for(int i=1;i<chars.size();++i)
        {
            if(chars[i]==ch)
                count++;
            else
            {
                if(count==1)
                    ans+=ch;
                else
                    ans=ans+ch+to_string(count);
                ch=chars[i];
                count=1;
            }
        }
        if(count==1)
            ans+=ch;
        else
            ans=ans+ch+to_string(count);
        cout<<ans;
        vector<char> st;
        for(int i=0;i<ans.size();++i)
        {
            st.push_back(ans[i]);
        }
        chars = st;
        return ans.size();
    }
};