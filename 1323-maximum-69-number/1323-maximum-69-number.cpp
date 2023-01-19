class Solution {
public:
    int maximum69Number (int num) 
    {
        string string_form = to_string(num);
        for(int i=0;i<string_form.size();++i)
        {
            if(string_form[i]=='6')
            {
                string_form[i]='9';
                break;
            }
        }
        return stoi(string_form);
    }
};