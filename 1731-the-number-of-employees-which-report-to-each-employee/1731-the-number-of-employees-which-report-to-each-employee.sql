# Write your MySQL query statement below
SELECT e.employee_id ,e.name,COUNT(f.employee_id) AS reports_count,
ROUND(AVG(f.age),0) AS average_age FROM Employees AS e
JOIN Employees as f ON e.employee_id=f.reports_to GROUP BY e.employee_id,e.name
ORDER BY e.employee_id;