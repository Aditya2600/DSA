-- # Write your MySQL query statement below
-- SELECT person_name
-- FROM (
--   SELECT
--     person_name,
--     SUM(weight) OVER (ORDER BY turn) AS total_weight
--   FROM Queue
-- ) AS temp
-- WHERE total_weight <= 1000
-- ORDER BY total_weight DESC
-- LIMIT 1;

SELECT q1.person_name
FROM Queue q1
INNER JOIN Queue q2
ON q1.turn >= q2.turn
GROUP BY q1.turn
HAVING SUM(q2.weight) <= 1000
ORDER BY SUM(q2.weight) DESC
LIMIT 1
