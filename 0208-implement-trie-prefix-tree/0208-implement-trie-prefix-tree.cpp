struct trie{
    trie* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,trie* node)
    {
        links[ch-'a']=node;
    }
    
    trie* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void setEnd()
    {
        flag=true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
public:
    trie* root;
    Trie() 
    {
        root = new trie();    
    }
    
    void insert(string word) 
    {
        trie* node = root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new trie());
            }
            node = node->get(word[i]);
        }
        node->setEnd();   
    }
    
    bool search(string word) 
    {
        trie* node = root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        trie* node = root;
        for(int i=0;i<prefix.size();++i)
        {
            if(!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */