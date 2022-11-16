class StockSpanner {
public:
    stack<pair<int,int>> s;
    int i;
    StockSpanner() 
    {
        i=0;   
    }
    
    int next(int price) 
    {
        i++;
        int x;
        while(!s.empty() && s.top().first<=price)
            s.pop();
        if(!s.empty())
            x = i-s.top().second;
        else
            x=i;
        s.push({price,i});
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */