class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int l1=num1.size();
        int l2=num2.size();
        string ans = "";
        for(int i=0;i<(l1+l2);++i)
            ans+='0';
        int carry=0,pf=0,k=(l1+l2)-1;
        for(int i=num1.size()-1;i>=0;--i)
        {
            for(int j=num2.size()-1;j>=0;--j)
            {
                int ival = num1[i]-48;
                int jval = num2[j]-48;
                int product = ival*jval + carry + (ans[k]-48);
                ans[k]=(product%10 + 48);
                carry=product/10;
                k--;
            }
            if(carry!=0)
            {
                ans[k]=(carry+48);
                carry=0;
            }
            pf++;
            k=(l1+l2)-1-pf;
        }
        if(carry!=0)
            ans[k]=(carry+48);
        int index = (l1+l2)-1;
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i]!='0')
            {
                index=i;
                break;
            }
        }
        ans.erase(ans.begin(),ans.begin()+index);
        return ans;
    }
};