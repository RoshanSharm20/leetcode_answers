class CustomStack {
public:
    stack<int> st;
    stack<int> temp;
    int size=0;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) 
    {
        if(st.size()+1<=size)
        {
            st.push(x);
        }
    }
    
    int pop() 
    {
        if(!st.empty())
        {
            int x = st.top();
            st.pop();
            return x;
        }
        else
            return -1;
    }
    
    void increment(int k, int val) 
    {
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        
        while(!temp.empty() && k>0)
        {
            int x = temp.top();
            temp.pop();
            st.push(x+val);
            k--;
        }
        while(!temp.empty())
        {
            int x = temp.top();
            temp.pop();
            st.push(x);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */