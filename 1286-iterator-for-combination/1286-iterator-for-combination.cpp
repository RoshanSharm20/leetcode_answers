class CombinationIterator {
public:
    vector<char> nodes;
    vector<string> ans;
    int position = 0;
    void solution(string& asf,int index,vector<char>& nodes,int& length)
    {
        if(asf.size()==length)
        {
            ans.push_back(asf);
            return;
        }
        if(index==nodes.size())
            return;
        for(int i=index;i<nodes.size();++i)
        {
            asf.push_back(nodes[i]);
            solution(asf,i+1,nodes,length);
            asf.pop_back();
        }
    }
    CombinationIterator(string characters, int length) 
    {
        // nodes.resize(characters.size(),'a');
        for(int i=0;i<characters.size();++i)
            nodes.push_back(characters[i]);
        sort(nodes.begin(),nodes.end());
        string asf="";
        solution(asf,0,nodes,length);
    }
    
    string next() 
    {
       return ans[position++];     
    }
    
    bool hasNext() 
    {
        return (position<=ans.size()-1);    
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */