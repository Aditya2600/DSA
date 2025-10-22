-- # Write your MySQL query statement below
-- SELECT id
-- FROM (
--   SELECT 
--     id,
--     temperature,
--     recordDate,
--     LAG(temperature, 1) OVER (ORDER BY recordDate) AS prev_temp,
--     LAG(recordDate, 1) OVER (ORDER BY recordDate) AS prev_date
--   FROM Weather
-- ) AS t
-- WHERE DATEDIFF(recordDate, prev_date) = 1
--   AND temperature > prev_temp;

SELECT w1.id
FROM Weather w1
INNER JOIN Weather w2
ON DateDiff(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;