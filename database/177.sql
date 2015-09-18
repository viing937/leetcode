CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT;
    SET M=N-1;
    RETURN (
        SELECT Salary FROM Employee GROUP BY Salary
        UNION ALL (SELECT null)
        ORDER BY Salary DESC LIMIT M,1
    );
END
