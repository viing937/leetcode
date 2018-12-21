SELECT DISTINCT Salary AS SecondHighestSalary FROM Employee
UNION ALL (SELECT NULL)
ORDER BY SecondHighestSalary DESC LIMIT 1,1
