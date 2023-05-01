class Solution {
public:
    double average(vector<int>& salary) 
    {
        double average_salary,max_value=0,min_value=0;
        max_value = *max_element(salary.begin(),salary.end());
        min_value = *min_element(salary.begin(),salary.end());
        int total_salary = accumulate(salary.begin(),salary.end(),0);
        int n = salary.size()-2;
        average_salary = (total_salary-max_value-min_value)/n;
        return average_salary;
    }
};