class MyCalendarThree {
public:
    map<int,int> nodes;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) 
    {
        nodes[startTime]++;
        nodes[endTime]--;
        
        int max_count=0,count=0;
        for(auto it:nodes)
        {
            count+=it.second;
            max_count = max(max_count,count);
        }
        return max_count;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */