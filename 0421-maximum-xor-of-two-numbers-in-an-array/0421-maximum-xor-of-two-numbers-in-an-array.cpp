struct Node {
    Node *links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    
    void put(int bit,Node *node)
    {
        links[bit]=node;
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
};

class Trie {
public:
    Node *root;
    
    Trie(){
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for(int i=31;i>=0;--i)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int getMax(int num)
    {
        int max_xor=0;
        Node *node=root;
        for(int i=31;i>=0;--i)
        {
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit))
            {
                max_xor=max_xor|(1<<i);
                node=node->get(1-bit);
            }
            else
                node=node->get(bit);
        }
        return max_xor;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie t;
        for(int i=0;i<nums.size();++i)
        {
            t.insert(nums[i]);
        }
        
        int max_val=0;
        for(int i=0;i<nums.size();++i)
        {
            max_val=max(max_val,t.getMax(nums[i]));
        }
        return max_val;
    }
};