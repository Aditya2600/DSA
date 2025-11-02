# Write your MySQL query statement below
WITH cte AS (SELECT *,
        ROW_NUMBER() OVER(PARTITION BY employee_id ORDER BY review_date DESC) AS rnk
FROM performance_reviews AS p),

cte2 AS(SELECT 
    employee_id, 
    SUM(CASE WHEN rnk = 1 THEN rating END) AS r1,
    SUM(CASE WHEN rnk = 2 THEN rating END) AS r2,
    SUM(CASE WHEN rnk = 3 THEN rating END) AS r3
FROM cte
WHERE rnk <= 3
GROUP BY employee_id)

SELECT c1.employee_id,
        e.name,
        (c1.r1 - c1.r3) AS improvement_score
FROM cte2 AS c1
LEFT JOIN employees AS e
ON c1.employee_id = e.employee_id
WHERE c1.r1 IS NOT NULL
AND c1.r2 IS NOT NULL
AND c1.r3 IS NOT NULL
AND c1.r1 > c1.r2
AND c1.r2 > c1.r3
ORDER BY improvement_score DESC, name;
