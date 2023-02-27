class Solution {
public:
    string complexNumberMultiply(string num1, string num2) 
    {
        int n1=num1.size();
        int n2=num2.size();
        int i=0,j=0;
        while(num1[i]!='+')
            i++;
        int num1_real = stoi(num1.substr(0,i));
        int num1_img = stoi(num1.substr(i+1,n1-1));
        while(num2[j]!='+')
            j++;
        int num2_real = stoi(num2.substr(0,j));
        int num2_img = stoi(num2.substr(j+1,n2-1));
        int ans_real = (num1_real*num2_real - num1_img*num2_img);
        int ans_img = (num1_real*num2_img + num1_img*num2_real);
        string ans = to_string(ans_real)+'+'+to_string(ans_img)+'i';
        return ans;
    }
};