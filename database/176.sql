select Salary from Employee group by Salary 
union all (select null)
order by Salary desc limit 1,1
