class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        string ans;
        int carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0 && j>=0)
        {
            int sum = (num1[i]-'0')+(num2[j]-'0')+carry;
            int rem = sum%10;
            carry=sum/10;
            ans.push_back(rem+48);
            i--;
            j--;
        }
        while(i>=0)
        {
            int sum = (num1[i]-'0')+carry;
            int rem = sum%10;
            carry = sum/10;
            ans.push_back(rem+48);
            i--;
        }
        while(j>=0)
        {
            int sum = (num2[j]-'0')+carry;
            int rem = sum%10;
            carry = sum/10;
            ans.push_back(rem+48);
            j--;
        }
        
        if(carry!=0)
        {
            ans.push_back(carry+48);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};