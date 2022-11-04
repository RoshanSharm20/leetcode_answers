class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num), temp = "";
        int c = 0;
        int i =0, j =0 ;
        while(j < str.size()){
            temp.push_back(str[j]);
            // j -i + 1
            if(j-i+1 == k){
               int tempnum = stoi(temp);
                if(tempnum && num % tempnum == 0)
                    c++;
                temp.erase(0,1);
                i++;
            }
            j++;
        }
        return c;
    }
};