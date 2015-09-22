DELETE FROM Person
WHERE Id NOT IN
(
    SELECT minId FROM
    (
        SELECT MIN(Id) AS minId FROM Person
        GROUP BY Email
    ) AS t
)
