class Solution {
public:
    int addDigits(int num) 
    {
     int result=0;
     while(num>0)
     {
         int rem = num%10;
         result = result+rem;
         num=num/10;
     }
     if((result/10)==0)
         return result;
     else
         return addDigits(result);
    }
};