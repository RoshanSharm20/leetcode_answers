class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        // bool alice_wins=false;
        int pairA=0,pairB=0;
        for(int i=1;i<colors.size()-1;++i)
        {
            if(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A')
                pairA++;
            else if(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B')
                pairB++;
        }
        
        if(pairA>pairB)
            return true;
        return false;
    }
};