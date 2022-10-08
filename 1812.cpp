class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        if ((coordinates[0] - 'a') % 2 == 0)
        {
            if ((coordinates[1] - '1') % 2 == 0)
                return false;
            else
                return true;
        }
        else
        {
            if ((coordinates[1] - '1') % 2 == 0)
                return true;
            else
                return false;
        }
    }
};