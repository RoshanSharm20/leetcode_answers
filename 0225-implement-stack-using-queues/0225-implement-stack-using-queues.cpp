class MyStack {
public:
    queue<int> q1,q2;
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q1.push(x);    
    }
    
    int pop() 
    {
        if(!q2.empty())
        {
            int x = q2.front();
            q2.pop();
            return x;
        }
        else
        {
            stack<int> Stack;
            while (!q1.empty()) {
                Stack.push(q1.front());
                q1.pop();
            }
            while (!Stack.empty()) {
                q2.push(Stack.top());
                Stack.pop();
            }
            int x = q2.front();
            q2.pop();
            return x;
        }
    }
    
    int top() 
    {
        if(!q1.empty())
            return q1.back();
        else if(!q2.empty())
            return q2.front();
        else
            return -1;
    }
    
    bool empty() 
    {
        return(q1.empty() && q2.empty());    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */