SELECT d.Name, e.Name, e.Salary
FROM Employee e JOIN Department d
ON e.DepartmentId = d.Id
WHERE e.Salary =
(
    SELECT MAX(Salary)
    FROM Employee
    WHERE DepartmentId = e.DepartmentId
)
