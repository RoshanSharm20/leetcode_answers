class MyHashMap
{
public:
    MyHashMap()
    {
    }
    map<int, int> v;
    void put(int key, int value)
    {
        v[key] = value;
    }

    int get(int key)
    {
        for (auto it : v)
        {
            if (it.first == key)
                return it.second;
        }
        return -1;
    }

    void remove(int key)
    {
        for (auto it : v)
        {
            if (it.first == key)
                v.erase(key);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */