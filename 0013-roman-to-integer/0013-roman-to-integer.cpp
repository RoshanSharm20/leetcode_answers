class Solution {
public:
    unordered_map<char,int> nodes;
    int count(int value)
    {
        int counter=0;
        while(value>0)
        {
            counter++;
            value/=10;
        }
        return counter;
    }
    int romanToInt(string s) 
    {
        nodes['I']=1;
        nodes['V']=5;
        nodes['X']=10;
        nodes['L']=50;
        nodes['C']=100;
        nodes['D']=500;
        nodes['M']=1000;
        int value=0;
        int curr_val=nodes[s[s.size()-1]];
        // int curr_val=0;
        // curr_val=nodes[s.size]
        for(int i=s.size()-2;i>=0;--i)
        {
            if(count(s[i])>count(s[i+1]))
            {
                value+=curr_val;
                curr_val=s[i];
            }
            else
            {
                if(nodes[s[i]]<nodes[s[i+1]])
                {
                    curr_val-=nodes[s[i]];
                }
                else
                {
                    cout<<curr_val<<" "<<value<<endl;
                    curr_val+=nodes[s[i]];
                }
            }
        }
        
        value+=curr_val;
        
        cout<<curr_val<<" "<<value<<endl;
        return value;
        
    }
};