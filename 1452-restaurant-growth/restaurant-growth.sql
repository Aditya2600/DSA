# Write your MySQL query statement below
WITH d AS (
  SELECT
    visited_on,
    SUM(amount) AS amount            -- per-day total
  FROM Customer
  GROUP BY visited_on
),
w AS (
  SELECT
    visited_on,
    SUM(amount) OVER (ORDER BY visited_on
                      ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
    AVG(amount)  OVER (ORDER BY visited_on
                      ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS avg_amt,
    COUNT(*)     OVER (ORDER BY visited_on
                      ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS cnt
  FROM d
)
SELECT
  visited_on,
  amount,
  ROUND(avg_amt, 2) AS average_amount
FROM w
WHERE cnt = 7;       -- only full 7-day windows