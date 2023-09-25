class Solution {
public:
    string intToRoman(int num) 
    {
        string str="";
        int factor=1;
        while(num>0)
        {
            int val = (num%10)*factor;
            
            if(val>=1 && val<=9)
            {
                if(val==4)
                    str+="VI";
                else if(val==9)
                    str+="XI";
                else if(val==5)
                    str+='V';
                else
                {
                    if(val<=3)
                    {
                        while(val>0)
                        {
                            str+='I';
                            val--;
                        }
                    }
                    else
                    {
                        val-=5;
                        while(val>0)
                        {
                            str+='I';
                            val--;
                        }
                        str+='V';
                    }
                }
            }
            
            else if(val>=10 && val<=90)
            {
                if(val==40)
                    str+="LX";
                else if(val==90)
                    str+="CX";
                else if(val==50)
                    str+='L';
                else
                {
                    if(val<=30)
                    {
                        while(val>0)
                        {
                            str+='X';
                            val-=10;
                        }
                    }
                    else
                    {
                        val-=50;
                        while(val>0)
                        {
                            str+='X';
                            val-=10;
                        }
                        str+='L';
                    }
                }
            }
            
            else if(val>=100 && val<=900)
            {
                if(val==400)
                    str+="DC";
                else if(val==900)
                    str+="MC";
                else if(val==500)
                    str+='D';
                else
                {
                    if(val<=300)
                    {
                        while(val>0)
                        {
                            str+='C';
                            val-=100;
                        }
                    }
                    else
                    {
                        val-=500;
                        while(val>0)
                        {
                            str+='C';
                            val-=100;
                        }
                        str+='D';
                    }
                }
            }
            else
            {
                while(val>0)
                {
                    str+='M';
                    val-=1000;
                }
            }
            factor=factor*10;
            num=num/10;
        }
        
        reverse(str.begin(),str.end());
        return str;
    }
};