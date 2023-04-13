class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i=0,j=0;
        stack<int> st;
        while(i<pushed.size())
        {
            if(!st.empty())
            {
                if(st.top()==popped[j])
                {
                    st.pop();
                    j++;
                }
                else
                {
                    st.push(pushed[i]);
                    i++;
                }
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }
        }
        while(!st.empty())
        {
            if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
            {
                break;
            }
        }
        if(j==popped.size())
            return true;
        return false;
    }
};