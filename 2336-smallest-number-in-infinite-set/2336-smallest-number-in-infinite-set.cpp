class SmallestInfiniteSet {
public:
    map<int,bool> Availablenodes;
    priority_queue<int,vector<int>,greater<int>> nodes;
    SmallestInfiniteSet() 
    {
        for(int i=1;i<=1000;++i)
        {
            nodes.push(i);
            Availablenodes[i]=true;
        }
    }
    
    int popSmallest() 
    {
        int smallest = nodes.top();
        nodes.pop();
        Availablenodes[smallest]=false;
        return smallest;
    }
    
    void addBack(int num) 
    {
        if(Availablenodes[num]==false)
        {
            nodes.push(num);
            Availablenodes[num]=true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */