SELECT DISTINCT Salary FROM Employee
UNION ALL (SELECT NULL)
ORDER BY Salary DESC LIMIT 1,1
