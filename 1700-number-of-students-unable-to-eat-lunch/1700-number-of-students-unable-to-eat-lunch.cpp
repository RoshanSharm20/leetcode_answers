class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int count=0;
        while(true)
        {
            if(students.size()==0)
                break;
            if(students.front()==sandwiches.front())
            {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                count=0;
            }
            else
            {
                int x = students.front();
                students.erase(students.begin());
                students.push_back(x);
                count++;
                if(count==students.size())
                    return count;
            }
        }
        return 0;
    }
};