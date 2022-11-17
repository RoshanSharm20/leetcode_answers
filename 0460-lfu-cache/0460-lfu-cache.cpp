struct Node
{
    int key;
    int value;
    int count;
    Node *next;
    Node *prev;
    Node(int _key,int _value)
    {
        key=_key;
        value=_value;
        count=1;
    }
    
};

struct List
{
    Node *head;
    Node *tail;
    int size;
    List()
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        size=0;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node *newnode)
    {
        newnode->next=head->next;
        newnode->prev=head;
        head->next->prev=newnode;
        head->next=newnode;
        size++;
    }
    
    void removeNode(Node *delnode)
    {
        Node *temp = delnode;
        temp->prev->next=temp->next;
        temp->next->prev = temp->prev;
        temp->next=NULL;
        temp->prev=NULL;
        size--;
    }
};
class LFUCache {
public:
    map<int,Node*> keyNode;
    map<int,List*> freqList;
    int maxSize,minFreq,curSize;
    LFUCache(int capacity) 
    {
        maxSize=capacity;
        minFreq=0;
        curSize=0;
    }
    
    void updateFreqListMap(Node *newnode)
    {
        keyNode.erase(newnode->key);
        freqList[newnode->count]->removeNode(newnode);
        
        if(newnode->count==minFreq && freqList[newnode->count]->size==0)
            minFreq++;
        
        List *nextHigherList = new List();
        if(freqList.find(newnode->count +1)!=freqList.end())
        {
            nextHigherList = freqList[newnode->count+1];
        }
        newnode->count+=1;
        nextHigherList->addNode(newnode);
        freqList[newnode->count]=nextHigherList;
        keyNode[newnode->key]=newnode;
    }
    int get(int key) 
    {
         if(keyNode.find(key)!=keyNode.end())
         {
             Node *newnode = keyNode[key];
             int val = newnode->value;
             updateFreqListMap(newnode);
             return val;
         }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(maxSize==0)
            return;
        
        if(keyNode.find(key)!=keyNode.end())
        {
            Node *newnode = keyNode[key];
            newnode->value = value;
            updateFreqListMap(newnode);
        }
        else
        {
            if(curSize==maxSize)
            {
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                curSize--;                
            }
            curSize++;
            
            minFreq=1;
            List *nextHigherList = new List();
            if(freqList.find(minFreq)!=freqList.end())
                nextHigherList = freqList[minFreq];
            
            Node *node = new Node(key,value);
            nextHigherList->addNode(node);
            keyNode[key]=node;
            freqList[minFreq]=nextHigherList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */