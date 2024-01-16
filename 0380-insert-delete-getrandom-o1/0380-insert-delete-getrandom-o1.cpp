class RandomizedSet {
public:
    unordered_set<int> nodes;
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(nodes.find(val)!=nodes.end())
            return false;
        nodes.insert(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if(nodes.find(val)==nodes.end())
            return false;
        nodes.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        int size = nodes.size();
        int index = rand()%size;
        int counter=0;
        
        for(auto it:nodes)
        {
            if(counter==index)
                return it;
            counter++;
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */