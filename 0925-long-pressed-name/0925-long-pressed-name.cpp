class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        if(name.size()>typed.size())
            return false;
        int i=0;
        int j=0;
        while(i<name.size() && j<typed.size())
        {
            if(name[i]==typed[j])
            {
                i++;
                j++;
            }
            else if(i>0 && typed[j]==name[i-1])
            {
                j++;
            }
            else
                return false;
        }
        while(j<typed.size())
        {
            if(name[i-1]!=typed[j])
                return false;
            j++;
        }
        
        if(i<name.size())
            return false;
        return true;
    }
};