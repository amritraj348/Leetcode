# Write your MySQL query statement below
SELECT e.name as Employee FROM Employee e
JOIN Employee f ON e.managerId=f.id
WHERE e.salary>f.salary;