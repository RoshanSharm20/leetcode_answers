class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> s;
        int total = 0;
        for(int i=0;i<operations.size();++i)
        {
            if(operations[i]=="+")
            {
                int op1=s.top();
                s.pop();
                int op2= s.top();
                int sum = op1+op2;
                s.push(op1);
                s.push(sum);
            }
            else if(operations[i]=="D")
            {
                int op1 = s.top();
                s.push(op1*2);
            }
            else if(operations[i]=="C")
                s.pop();
            else
            {
                int x = stoi(operations[i]);
                s.push(x);
            }
        }
        while(!s.empty())
        {
            total+=s.top();
            s.pop();
        }
        return total;
    }
};