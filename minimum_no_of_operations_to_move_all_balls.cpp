class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> ans;
        for (int i = 0; i < boxes.size(); i++)
        {
            int count = 0;
            for (int j = boxes.size(); j >= 0; j--)
            {
                if ((i != j) && (boxes[j] == '1')) // compare the string characters
                    count += (abs(j - i));         // store the absolute difference
            }
            ans.push_back(count);
        }
        return ans;
    }
};