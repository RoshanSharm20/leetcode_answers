class Solution {
public:
    //using gray code method
    vector<string> generate(int n)
    {
        if(n==1)
        {
            vector<string> t={"0","1"};
            return t;
        }
        vector<string> temp = generate(n-1);
        vector<string> ans;
        for(int i=0;i<temp.size();++i)
            ans.push_back("0"+temp[i]);
        for(int i=temp.size()-1;i>=0;--i)
        {
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
    vector<int> circularPermutation(int n, int start) 
    {
        vector<string> temp = generate(n);
        vector<int> ans;
        int index=0;
        for(int i=0;i<temp.size();++i)
        {
            int num = stoi(temp[i],0,2);
            ans.push_back(num);
            if(num==start)
                index = i;
        }
        
        vector<int> finans;
        for(int i=index;i<ans.size();++i)
            finans.push_back(ans[i]);
        for(int i=0;i<index;++i)
            finans.push_back(ans[i]);
        return finans;
    }
};