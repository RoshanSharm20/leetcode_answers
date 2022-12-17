class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int> st;
        for(int i=0;i<tokens.size();++i)
        {
            if(tokens[i]=="+")
            {
                long long int n1=st.top();
                st.pop();
                long long int n2=st.top();
                st.pop();
                n2=n1+n2;
                st.push(n2);
            }
            else if(tokens[i]=="-")
            {
                long long int n1=st.top();
                st.pop();
                long long int n2=st.top();
                st.pop();
                n2=n2-n1;
                st.push(n2);
            }
            else if(tokens[i]=="*")
            {
                long long int n1=st.top();
                st.pop();
                long long int n2=st.top();
                st.pop();
                n1=n1*n2;
                st.push(n1);
            }
            else if(tokens[i]=="/")
            {
                long long int n1=st.top();
                st.pop();
                long long int n2=st.top();
                st.pop();
                n1=n2/n1;
                st.push(n1);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        int ans = st.top();
        return ans;
    }
};