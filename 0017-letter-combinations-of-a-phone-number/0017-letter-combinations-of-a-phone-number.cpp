class Solution {
public:
    void solution(int index,string &digits,unordered_map<int,string> &list,string &asf,vector<string> &ans)
    {
        if(index==digits.size())
        {
            if(asf.size()>0)
                ans.push_back(asf);
            return;
        }
        
        int val = int(digits[index]-'0');
        string possible = list[val];
        for(int i=0;i<possible.size();++i)
        {
            asf.push_back(possible[i]);
            solution(index+1,digits,list,asf,ans);
            asf.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<int,string> list;
        list[2]="abc";
        list[3]="def";
        list[4]="ghi";
        list[5]="jkl";
        list[6]="mno";
        list[7]="pqrs";
        list[8]="tuv";
        list[9]="wxyz";
        
        vector<string> ans;
        string asf="";
        solution(0,digits,list,asf,ans);
        return ans;
    }
};