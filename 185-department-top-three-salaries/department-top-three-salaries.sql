# Write your MySQL query statement below
SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM 
    Employee e
JOIN 
    Department d ON e.departmentId = d.id
JOIN (
    SELECT 
        id AS employeeId,
        salary,
        departmentId,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM 
        Employee
) t ON e.id = t.employeeId
WHERE 
    t.rnk <= 3
ORDER BY 
    d.name,
    e.salary DESC;
